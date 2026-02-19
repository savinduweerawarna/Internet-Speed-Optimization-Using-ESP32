import socket, threading, binascii, time

LISTEN_HOST = "0.0.0.0"
LISTEN_PORT = 8080

UPSTREAM_HOST = "xxxxxxxx"
UPSTREAM_PORT = 8080

def hexdump(prefix, data):
    print(f"{prefix} {len(data)} bytes")
    print(binascii.hexlify(data).decode())

def pipe(src, dst, tag):
    while True:
        data = src.recv(4096)
        if not data:
            break
        hexdump(tag, data)
        dst.sendall(data)

def handle(client_sock, addr):
    print("Client connected:", addr)
    upstream = socket.create_connection((UPSTREAM_HOST, UPSTREAM_PORT))
    t1 = threading.Thread(target=pipe, args=(client_sock, upstream, "ESP32 -> SRV:"))
    t2 = threading.Thread(target=pipe, args=(upstream, client_sock, "SRV  -> ESP32:"))
    t1.start(); t2.start()
    t1.join(); t2.join()
    client_sock.close()
    upstream.close()
    print("Closed:", addr)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((LISTEN_HOST, LISTEN_PORT))
s.listen(5)
print(f"Listening on {LISTEN_HOST}:{LISTEN_PORT} forwarding to {UPSTREAM_HOST}:{UPSTREAM_PORT}")

while True:
    c, a = s.accept()
    threading.Thread(target=handle, args=(c, a), daemon=True).start()
