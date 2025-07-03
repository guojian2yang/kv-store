


import socket

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_address = ('192.168.31.43', 2000)  

    try:
        client_socket.connect(server_address)

        message = "del teacher"
        client_socket.sendall(message.encode())

        response = client_socket.recv(1024)
        
        print("recv:", response.decode())
    
    except Exception as e:
        print("发生异常:", str(e))
    
    finally:
        client_socket.close()

if __name__ == '__main__':
    main()


