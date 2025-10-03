#!/usr/bin/python3
"""Log parsing script that computes metrics from stdin"""

import sys
import re


def print_stats(total_size, status_codes):
    """Print statistics: total file size and status code counts"""
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        print(f"{code}: {status_codes[code]}")


def parse_log():
    """Parse log lines from stdin and compute metrics"""
    total_size = 0
    status_codes = {}
    line_count = 0

    # Regex pattern to match the log format
    pattern = re.compile(
        r'^(\S+) - \[(.+?)\] "GET /projects/260 HTTP/1\.1" '
        r'(\d+) (\d+)

    try:
        for line in sys.stdin:
            line = line.strip()
            match = pattern.match(line)

            if match:
                status_code = int(match.group(3))
                file_size = int(match.group(4))

                # Update metrics
                total_size += file_size

                # Only track valid status codes
                valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]
                if status_code in valid_codes:
                    status_codes[status_code] = status_codes.get(
                        status_code, 0) + 1

                line_count += 1

                # Print stats every 10 lines
                if line_count % 10 == 0:
                    print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        # Print stats on keyboard interruption
        print_stats(total_size, status_codes)
        raise

    # Print final stats if not already printed or if no lines processed
    if line_count % 10 != 0 or line_count == 0:
        print_stats(total_size, status_codes)


if __name__ == "__main__":
    parse_log()

    )

    try:
        for line in sys.stdin:
            line = line.strip()
            match = pattern.match(line)

            if match:
                status_code = int(match.group(3))
                file_size = int(match.group(4))

                # Update metrics
                total_size += file_size

                # Only track valid status codes
                valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]
                if status_code in valid_codes:
                    status_codes[status_code] = status_codes.get(
                        status_code, 0) + 1

                line_count += 1

                # Print stats every 10 lines
                if line_count % 10 == 0:
                    print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        # Print stats on keyboard interruption
        print_stats(total_size, status_codes)
        raise

    # Print final stats if not already printed or if no lines processed
    if line_count % 10 != 0 or line_count == 0:
        print_stats(total_size, status_codes)


if __name__ == "__main__":
    parse_log()
