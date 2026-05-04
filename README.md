# Making Your Research Reproducible, Usable, and Visible

## Overview

AI research output is growing fast, and making your work stand out matters more than ever. One effective way to increase impact is to make your research reproducible, usable, and visible.

In this workshop, you will learn to use GitHub, manage dependencies, and publish your methods to reach a broader audience. By the end, you will have turned an example research methodology into a public Python package.

## What you will learn

- Version-controlling a research project with Git and GitHub
- Managing Python environments and dependencies with `venv`, `pip`, and `uv`
- Containerizing a project with Docker
- Packaging and publishing code to PyPI / TestPyPI

## Slides

The slides are available under the `slides/` directory:

- [Git and GitHub](slides/git.pdf)
- [Dependency Management: venv, pip, uv](slides/dependency.pdf)
- [Docker](slides/docker.pdf)

## Publishing to TestPyPI

We publish our package to [TestPyPI](https://test.pypi.org) instead of the official [PyPI](https://pypi.org), because we do not want to clutter the official index with experimental packages :)

1. Create an account at [https://test.pypi.org](https://test.pypi.org) and generate an API token.
2. Change the project name in `pyproject.toml` and `mypackage/__init__.py`. The name must be unique across TestPyPI.
3. Build the project:

```bash
   uv build
```

4. Publish to the index:

```bash
   uv publish --publish-url https://test.pypi.org/legacy/ --token [TOKEN]
```

5. Start a fresh environment to test the install:

```bash
   mkdir ~/temp && cd ~/temp
   uv init
   uv pip install -i https://test.pypi.org/simple/ --extra-index-url https://pypi.org/simple/ research_workshop_1
   # change research_workshop_1 to your module name
```

6. Test your package CLI in the new environment:

```bash
   uv run sentiment "today is a good day"
```

7. Create a `main.py` file with the following content:

```python
   # file main.py
   import mypackage

   if __name__ == "__main__":
       text = "Today is a good day :)"
       print(mypackage.predict(text))
```

   Then run:

```bash
   uv run main.py
```
