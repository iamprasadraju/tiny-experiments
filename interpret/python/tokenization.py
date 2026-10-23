#!/usr/bin/env python3

def read(file_path):
    try:
        with open(file_path, "r") as source: return source.read().strip()
    except: source.close()

def tokenizer(code: str):
    tokens = []
    lines = code.split("\n")
    indent = [" " * 4]
    for line in lines:
        c_line = line.lstrip(indent[0]) # tab
        if c_line: tokens.append((len(line) - len(c_line)) // 4 * indent + c_line.split(" "))
    return tokens

if __name__ == "__main__":
    file = "source.py"

    ts = tokenizer(read(file))

    for t in ts:
        print(t)

    print("\n ------------------ \n")

        
    import tokenize
    from io import BytesIO
    
    
    code = read(file)
    code_bytes = code.encode('utf-8')    
    tokens = tokenize.tokenize(BytesIO(code_bytes).readline)
    for token in tokens:
        print(token)
