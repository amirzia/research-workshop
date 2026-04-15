from importlib.metadata import version
from .model import predict

__all__ = ["predict"]
__version__ = version("research-workshop-1")
