import os
import subprocess

def open(url, title="fxhtml", width=800, height=600):
    """Open a URL in fxhtml viewer."""
    size = f"{width}x{height}"
    cmd = ["/opt/fxhtml/fxhtml", url, "--title", title, "--size", size]
    subprocess.Popen(cmd, start_new_session=True)
