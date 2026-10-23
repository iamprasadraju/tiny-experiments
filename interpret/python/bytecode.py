import dis

def bytecode(filepath):
    with open(filepath, "r", encoding="utf-8") as source:
        source = source.read()
    return dis.dis(source)

if __name__ == "__main__":
    print(bytecode("source.py"))
