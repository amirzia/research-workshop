
# Marking Your Research Reproducible, Usable and Visible

## Overview

With the rapid growth of AI research, publications are multiplying rapidly. It has become more crucial than ever for researchers to make their work stand out. One effective way to increase the impact of research is to make it reproducible, usable, and visible.

In this workshop, participants will learn to use GitHub, manage dependencies, and publish their methods to reach a broader audience. Participants will turn an example research methodology into a public Python package.

## Slides

The slides are available under the `slides/` directory:
- [Git and Github](slides/git.pdf)
- [Dependency Management: venv, pip, uv](slides/dependency.pdf)

## TestPyPi

We want to publish our package to TestPyPi ([https://test.pypi.org](https://test.pypi.org))
instead of the official PyPi ([https://pypi.org](https://pypi.org)). That is becasue we do not want to spoil the
official index with experimental packages :) 

1. Make an account at [https://test.pypi.org](https://test.pypi.org) and create an API token.
2. Change the project name in the `pyproject.toml` file and `mypackage/__init__.py`. The name should be unique across the TestPyPi.
3. Build the project with `uv build`
4. Publish your code to the index: `uv publish --publish-url https://test.pypi.org/legacy/ --token [TOKEN]`
5. To test, start a fresh environment:
   ```{bash}
   mkdir ~/temp && cd ~/temp
   uv init
   uv pip install -i https://test.pypi.org/simple/ --extra-index-url https://pypi.org/simple/ research_workshop_1  # change the research_workshop_1 to your module name
   ```
6. Test your package CLI in the new environment:
   ```{bash}
   uv run sentiment "today is a good day"`
   ```
7. Create the file `main.py` with the following content:
   ```{bash}
   # file main.py
   import mypackage
   
   if __name__ == "__main__":
       text = "Today is a good day :)"
       print(mypackage.predict(text))
   ```
   Then, issue `uv run main.py`.
