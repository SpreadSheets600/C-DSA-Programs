import os
import shutil
import yaml
import re

SOURCE_DIR = "."
DOCS_DIR = ".github/docs"

def copy_docs():
    if os.path.exists(DOCS_DIR):
        shutil.rmtree(DOCS_DIR)
    os.makedirs(DOCS_DIR)

    allowed_ext = (".md", ".ipynb", ".png", ".jpg", ".jpeg", ".gif", ".svg", ".cpp", ".c", ".h", ".hpp", ".txt")

    for root, dirs, files in os.walk(SOURCE_DIR):
        if DOCS_DIR in root or ".git" in root or ".github" in root:
            continue

        rel_path = os.path.relpath(root, SOURCE_DIR)
        dest_path = os.path.join(DOCS_DIR, rel_path)
        os.makedirs(dest_path, exist_ok=True)

        for file in files:
            if file.lower().endswith(allowed_ext):
                shutil.copy2(os.path.join(root, file), os.path.join(dest_path, file))



def fix_markdown_paths(file_path):
    with open(file_path, "r", encoding="utf-8") as f:
        content = f.read()

    content = re.sub(r'\.\./\.github/', '', content)

    with open(file_path, "w", encoding="utf-8") as f:
        f.write(content)



def scan_dir(base_dir):
    nav_entries = []

    for root, dirs, files in os.walk(base_dir):
        dirs.sort()
        files.sort()

        md_files = [f for f in files if f.endswith(".md") or f.endswith(".ipynb")]
        if not md_files:
            continue

        rel_dir = os.path.relpath(root, base_dir)
        section_name = os.path.basename(root) if rel_dir != "." else "Home"

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
            nav_entries.append({section_name: pages})
        else:
            pages = []
            for f in md_files:
                title = os.path.splitext(f)[0].replace("-", " ")
                pages.append({title: os.path.join(rel_dir, f)})
            nav_entries.append({section_name: pages})

    return nav_entries


def build_mkdocs(nav_entries):
    config = {
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
        "repo_url": "https://github.com/SpreadSheets600/c-dsa-programs",
        "repo_name": "C-DSA-Programs",
        "nav": nav_entries,
    }
    return config

import re

def copy_missing_images():
    for root, _, files in os.walk(DOCS_DIR):
        for file in files:
            if file.lower().endswith(".md"):
                md_path = os.path.join(root, file)
                with open(md_path, "r", encoding="utf-8") as f:
                    content = f.read()

                matches = re.findall(r'!\[.*?\]\((.*?)\)', content)
                for match in matches:
                    src_md_rel_path = os.path.relpath(md_path, DOCS_DIR)  
                    orig_md_path = os.path.join(SOURCE_DIR, src_md_rel_path)  
                    orig_md_dir = os.path.dirname(orig_md_path)  

                    img_source = os.path.normpath(os.path.join(orig_md_dir, match))
                    img_dest = os.path.normpath(os.path.join(root, match))

                    os.makedirs(os.path.dirname(img_dest), exist_ok=True)

                    if os.path.exists(img_source):
                        shutil.copy2(img_source, img_dest)




if __name__ == "__main__":
    copy_docs()

    for root, _, files in os.walk(DOCS_DIR):
        for file in files:
            if file.lower().endswith(".md"):
                fix_markdown_paths(os.path.join(root, file))

    nav = scan_dir(DOCS_DIR)
    config = build_mkdocs(nav)

    with open("mkdocs.yml", "w") as f:
        yaml.dump(config, f, sort_keys=False)

    copy_missing_images()


    print("✅ mkdocs.yml generated and docs folder prepared")
