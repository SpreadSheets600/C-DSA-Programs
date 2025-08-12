import os
import yaml
import shutil
import pathlib

SOURCE_DIR = "."
DOCS_DIR = ".github/docs"
MKDOCS_FILE = "mkdocs.yml"
OVERRIDES_DIR = "overrides"
ASSETS_DIR = os.path.join(DOCS_DIR, "assets")
CUSTOM_CSS = os.path.join(ASSETS_DIR, "extra.css")

ALLOWED_EXT = (
    ".md",
    ".ipynb",
    ".png",
    ".jpg",
    ".jpeg",
    ".gif",
    ".svg",
    ".cpp",
    ".c",
    ".h",
    ".hpp",
    ".txt",
    ".css",
)


def wrap_code_as_md(src_path, dest_path):
    lang = pathlib.Path(src_path).suffix.lstrip(".")
    with open(src_path, "r", encoding="utf-8", errors="ignore") as src, open(
        dest_path, "w", encoding="utf-8"
    ) as md:
        md.write(f"# {os.path.basename(src_path)}\n\n")
        md.write(f"```{lang}\n")
        md.write(src.read())
        md.write("\n```")


def copy_docs():
    if os.path.exists(DOCS_DIR):
        shutil.rmtree(DOCS_DIR)

    os.makedirs(DOCS_DIR)

    for root, _, files in os.walk(SOURCE_DIR):
        if any(
            skip in root
            for skip in [DOCS_DIR, ".git", ".github", "site", ".vscode", OVERRIDES_DIR]
        ):
            continue

        rel_path = os.path.relpath(root, SOURCE_DIR)
        dest_path = os.path.join(DOCS_DIR, rel_path)
        os.makedirs(dest_path, exist_ok=True)

        for file in files:
            src_file = os.path.join(root, file)

            if file.lower().endswith(ALLOWED_EXT):
                shutil.copy2(src_file, os.path.join(dest_path, file))

                if file.lower().endswith((".cpp", ".c", ".h", ".hpp", ".txt")):
                    md_name = os.path.splitext(file)[0] + ".md"
                    wrap_code_as_md(src_file, os.path.join(dest_path, md_name))


def ensure_custom_css():
    os.makedirs(ASSETS_DIR, exist_ok=True)

    if not os.path.exists(CUSTOM_CSS):
        with open(CUSTOM_CSS, "w", encoding="utf-8") as f:
            f.write(
                """
    .md-main__inner {
        max-width: 2000px;
        margin-left: auto !important;
        margin-right: auto !important;
    }

    .md-content {
        padding-left: 2rem !important;
        padding-right: 2rem !important;
        border-left: 1px solid rgb(64, 81, 181, 0.5) !important;
        border-right: 1px solid rgba(64, 82, 181, 0.5) !important;
    }
"""
            )


def ensure_mkdocs_extra_css():
    if not os.path.exists(MKDOCS_FILE):
        print(f"⚠ {MKDOCS_FILE} Not Found! 404")
        return

    with open(MKDOCS_FILE, "r", encoding="utf-8") as f:
        config = yaml.safe_load(f)

    extra_css_list = config.get("extra_css", [])

    if f"assets/{os.path.basename(CUSTOM_CSS)}" not in extra_css_list:
        extra_css_list.append(f"assets/{os.path.basename(CUSTOM_CSS)}")
        config["extra_css"] = extra_css_list

        with open(MKDOCS_FILE, "w", encoding="utf-8") as f:
            yaml.dump(config, f, sort_keys=False)

        print(f"✅ Added {CUSTOM_CSS} TO {MKDOCS_FILE}")


def scan_dir(base_dir):
    nav_entries = {}
    md_exts = (".md",)

    for root, dirs, files in os.walk(base_dir):
        dirs.sort()
        files.sort()

        md_files = [f for f in files if f.lower().endswith(md_exts)]
        if not md_files:
            continue

        rel_dir = os.path.relpath(root, base_dir)
        section_name = os.path.basename(root) if rel_dir != "." else "Home"

        if rel_dir == ".":
            parent_name = "."
        else:
            parent_name = os.path.basename(os.path.dirname(root))
            if parent_name == os.path.basename(base_dir):
                parent_name = "."

        pages = []

        if "README.md" in md_files:
            readme_path = (
                os.path.join(rel_dir, "README.md") if rel_dir != "." else "README.md"
            )
            pages.append({section_name: readme_path})
            for f in sorted(md_files):
                if f == "README.md":
                    continue
                title = os.path.splitext(f)[0].replace("-", " ")
                pages.append({title: os.path.join(rel_dir, f)})
        else:
            for f in sorted(md_files):
                title = os.path.splitext(f)[0].replace("-", " ")
                pages.append({title: os.path.join(rel_dir, f)})

        if parent_name != ".":
            nav_entries.setdefault(parent_name, []).append({section_name: pages})
        else:
            nav_entries.setdefault(section_name, pages)

    final_nav = [{key: value} for key, value in nav_entries.items()]
    return final_nav


def build_mkdocs(nav_entries):
    return {
        "site_name": "C DSA Programs",
        "docs_dir": ".github/docs",
        "theme": {
            "name": "material",
            "palette": [
                {
                    "scheme": "default",
                    "primary": "indigo",
                    "accent": "pink",
                    "toggle": {
                        "icon": "material/weather-night",
                        "name": "Switch to dark mode",
                    },
                },
                {
                    "scheme": "slate",
                    "primary": "indigo",
                    "accent": "pink",
                    "toggle": {
                        "icon": "material/weather-sunny",
                        "name": "Switch to light mode",
                    },
                },
            ],
            "features": [
                "navigation.instant",
                "navigation.expand",
                "navigation.sections",
                "navigation.path",
                "navigation.prune",
                "search.highlight",
                "search.suggest",
                "content.code.copy",
            ],
        },
        "markdown_extensions": [
            "admonition",
            "codehilite",
            "footnotes",
            "tables",
            "toc",
            {
                "pymdownx.highlight": {
                    "anchor_linenums": True,
                    "linenums": True,
                    "linenums_style": "table",
                    "use_pygments": True,
                }
            },
            "pymdownx.superfences",
        ],
        "extra_css": [f"assets/{os.path.basename(CUSTOM_CSS)}"],
        "plugins": ["search", "mkdocs-jupyter", "offline", "tags"],
        "repo_url": "https://github.com/SpreadSheets600/C-DSA-Programs",
        "repo_name": "C-DSA-Programs",
        "nav": nav_entries,
    }


if __name__ == "__main__":
    copy_docs()
    ensure_custom_css()
    ensure_mkdocs_extra_css()

    nav = scan_dir(DOCS_DIR)
    config = build_mkdocs(nav)

    with open("mkdocs.yml", "w") as f:
        yaml.dump(config, f, sort_keys=False)

    print("✅ MkDocs configuration generated successfully with custom CSS support!")
