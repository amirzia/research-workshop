from pathlib import Path
from huggingface_hub import snapshot_download

MODEL_ID = "distilbert-base-uncased-finetuned-sst-2-english"
_CACHE_DIR = Path.home() / ".cache" / "workshop_demo"


def _load():
    if not _CACHE_DIR.exists():
        # Download on first use; subsequent calls hit local cache instantly
        snapshot_download(
            repo_id=MODEL_ID,
            local_dir=_CACHE_DIR,
        )

    from transformers import pipeline
    return pipeline("sentiment-analysis", model=str(_CACHE_DIR), )


def predict(text: str) -> dict:
    """Return {'label': 'POSITIVE'|'NEGATIVE', 'score': float}."""
    return _load()(text)[0]


def cli():
    import sys
    if len(sys.argv) < 2:
        print("Usage: sentiment <text>")
        sys.exit(1)
    text = sys.argv[1]
    result = predict(text)
    print(f"{result['label']}  ({result['score']:.2%})")

