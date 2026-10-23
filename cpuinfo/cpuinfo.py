#!/usr/bin/env python3

import platform
import os
import psutil
import subprocess

import plistlib

# colors
GREEN = "\033[38;2;0;255;0m"
RESET = "\033[0m"


def format_info(title, value):
    return f"{GREEN}{title}{RESET} : {value}"

os_type = platform.system()
if os_type == "Darwin":
    chip_name = format_info("Chip", subprocess.check_output(["sysctl", "-n", "machdep.cpu.brand_string"]).decode().strip())
    print(chip_name)

elif os_type == "Windows":
    chip_name = format_info("Chip", platform.processor())

else:
    result = subprocess.run(["lscpu"], shell=True, capture_output=True, text=True)
    for item in result.stdout.split("\n"):
        i, v = item.split(":")
        if i == "Model name":
            print(format_info("Chip", v.lstrip()))
            break

# no of cores
n_cores = format_info("Number of Cores", psutil.cpu_count(logical=False))
print(n_cores)


# no of hardware threads
n_threads = format_info("Number of Hardware Threads", psutil.cpu_count(logical=True))
print(n_threads)

# onpaper per core clock-speed
min_cs, max_cs = psutil.cpu_freq()[1:]

clock_speed = format_info("Clock Speed", f"Min={min_cs} MHz, Max={max_cs} MHz ")
print(clock_speed)


# cache hierarchy (l1, l2, l3)

# Become a project -> https://github.com/iamprasadraju/cpuperf 
