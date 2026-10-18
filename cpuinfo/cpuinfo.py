#!/usr/bin/env python3

import platform
import os, shutil
import subprocess

# colors
GREEN = "\033[38;2;0;255;0m"
RESET = "\033[0m"

os_type = platform.system()
if os_type == "Darwin":
    print(f"{GREEN}Chip:{RESET}", subprocess.check_output(["sysctl", "-n", "machdep.cpu.brand_string"]).decode().strip())

elif os_type == "Windows":
    print(platform.processor())
else:
    result = subprocess.run(["lscpu"], shell=True, capture_output=True, text=True)
    for item in result.stdout.split("\n"):
        i, v = item.split(":")
        print(f"{GREEN}{i}{RESET}:", v)
