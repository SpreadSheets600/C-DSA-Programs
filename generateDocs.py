import os
import shutil
import yaml

SOURCE_DIR = "."
DOCS_DIR = ".github/docs"

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
)


def copy_docs():
    if os.path.exists(DOCS_DIR):
        shutil.rmtree(DOCS_DIR)
        
    os.makedirs(DOCS_DIR)

    for root, _, files in os.walk(SOURCE_DIR):
        if any(skip in root for skip in [DOCS_DIR, ".git", ".github"]):
            continue

        rel_path = os.path.relpath(root, SOURCE_DIR)
        dest_path = os.path.join(DOCS_DIR, rel_path)
        os.makedirs(dest_path, exist_ok=True)

        for file in files:
            if file.lower().endswith(ALLOWED_EXT):
                shutil.copy2(os.path.join(root, file), os.path.join(dest_path, file))


def scan_dir(base_dir):
    nav_entries = {}

    for root, dirs, files in os.walk(base_dir):
        dirs.sort()
        files.sort()

        md_files = [f for f in files if f.lower().endswith(".md")]
        if not md_files:
            continue

        rel_dir = os.path.relpath(root, base_dir)
        section_name = os.path.basename(root) if rel_dir != "." else "Home"
        parent_name = os.path.basename(os.path.dirname(root))

        if "README.md" in md_files:
            readme_path = (
                os.path.join(rel_dir, "README.md") if rel_dir != "." else "README.md"
            )
            pages = [{section_name: readme_path}]
            for f in md_files:
                if f == "README.md":
                    continue
                title = os.path.splitext(f)[0].replace("-", " ")
                pages.append({title: os.path.join(rel_dir, f)})
        else:
            pages = []
            for f in md_files:
                title = os.path.splitext(f)[0].replace("-", " ")
                pages.append({title: os.path.join(rel_dir, f)})

        if parent_name != ".":
            nav_entries.setdefault(parent_name, []).append({section_name: pages})
        else:
            nav_entries.setdefault(section_name, pages)

    final_nav = [{key: value} for key, value in nav_entries.items()]
    return final_nav


def build_mkdocs(nav_entries):
    """Build MkDocs configuration."""
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
        "plugins": ["search", "mkdocs-jupyter"],
        "repo_url": "https://github.com/SpreadSheets600/C-DSA-Programs",
        "repo_name": "C-DSA-Programs",
        "nav": nav_entries,
    }


if __name__ == "__main__":
    copy_docs()
    nav = scan_dir(DOCS_DIR)
    config = build_mkdocs(nav)

    with open("mkdocs.yml", "w") as f:
        yaml.dump(config, f, sort_keys=False)

    print("✅ mkdocs.yml generated and docs folder prepared")
