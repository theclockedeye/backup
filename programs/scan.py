import subprocess
import ipaddress
import socket
import threading
import os

def ping_ip(ip, results):
    """Ping an IP address and return its status."""
    command = ['ping', '-n', '1', str(ip)]  # Use '-c' for Unix/Linux
    response = subprocess.call(command, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    status = "Alive" if response == 0 else "Not reachable"
    results[ip] = status
    print(f"Checked {ip}: {status}")

def get_device_name(ip):
    """Get the device name associated with an IP address."""
    try:
        return socket.gethostbyaddr(str(ip))[0]
    except socket.herror:
        return "Unknown"

def scan_network(network_prefix):
    """Scan the network for connected devices."""
    results = {}
    threads = []

    # Create a list of IP addresses in the subnet
    network = ipaddress.ip_network(network_prefix)

    print("Scanning network for devices...")

    # Create threads for each IP address
    for ip in network.hosts():
        thread = threading.Thread(target=ping_ip, args=(ip, results))
        threads.append(thread)
        thread.start()

    # Wait for all threads to complete
    for thread in threads:
        thread.join()

    print("\nScan complete.")

    # Process results
    print("\nConnected Devices:")
    print("IP Address          Device Name")
    print("=================================")

    for ip in results:
        if results[ip] == "Alive":
            device_name = get_device_name(ip)
            print(f"{str(ip):<20} {device_name}")  # Convert IP to string

def list_networks():
    """List available networks using 'netsh' on Windows."""
    print("Available Networks:")
    os.system('netsh wlan show networks')

def main():
    # List available networks
    list_networks()

    # Example network prefix (change as necessary)
    network_prefix = "192.168.43.0/24"  # Adjust this to your network
    scan_network(network_prefix)

if __name__ == "__main__":
    main()
