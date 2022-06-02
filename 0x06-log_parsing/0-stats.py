#!/usr/bin/python3
"""
Print server log stats
"""
import sys


def print_stats(file_size, codes):
    """Print the stats"""
    print("File size: {}".format(file_size))
    [print("{}: {}".format(code, codes[code]))
     for code in sorted(codes.keys()) if codes[code] != 0]


def stdin_data():
    """Get data form standard input"""
    codes = {
		"200": 0,
		"301": 0,
		"400": 0,
		"401": 0,
		"403": 0,
		"404": 0,
		"405": 0,
		"500": 0
	}
    file_size = 0
    line_count = 0
    try:
        while True:
            try:
                line = input()
                data = line.split()
                if data and len(data) > 2:
                    line_count += 1
                    file_size += int(data[-1])
                    try:
                        codes[data[-2]] += 1
                    except Exception:
                        pass
                if line_count >= 10:
                    print_stats(file_size, codes)
                    line_counts = 0
            except EOFError:
                if line_count < 10:
                    print_stats(file_size, codes)
                break
    except KeyboardInterrupt:
        print_stats(file_size, codes)


if __name__ == "__main__":
    stdin_data()
