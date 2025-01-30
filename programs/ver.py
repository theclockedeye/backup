import psutil as p

def convert_size(size_bytes):
    """Convert bytes to KB, MB, GB, or TB."""
    if size_bytes == 0:
        return "0B"

    # Define size units
    size_units = ["B", "KB", "MB", "GB", "TB", "PB"]
    i = 0

    # Keep dividing by 1024 to find the appropriate unit
    while size_bytes >= 1024 and i < len(size_units) - 1:
        size_bytes /= 1024.0
        i += 1

    return f"{size_bytes:.2f} {size_units[i]}"

# Get the list of all disk partitions
partitions = p.disk_partitions()

# Iterate through each partition and get its usage
for partition in partitions:
    print(f"Partition: {partition.device}")
    usage = p.disk_usage(partition.mountpoint)

    size = convert_size(usage.total)
    free = convert_size(usage.free)

    print(f'Size: {size}')
    print(f'Free: {free}\n')
