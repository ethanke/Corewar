#!/usr/bin/python
from BaseHTTPServer import HTTPServer
from BaseHTTPServer import BaseHTTPRequestHandler
from subprocess import call
import cgi
import os

PORT = 666
FILE_PREFIX = "./JSON"
CHAMP_PREFIX = "../champion/"
EXECUTABLE = "./corewar"

# ARGUMENT PARSING #
if __name__ == "__main__":
    try:
        import argparse
        parser = argparse.ArgumentParser(description='Coquilettes jambon! Server corewar')
        parser.add_argument('-p', '--port', type=int, dest="PORT",
                           help='the port to run the server on; defaults to 666')
        args = parser.parse_args()
        if args.PORT:
            PORT = args.PORT
    except Exception:
        pass
# ARGUMENT PARSING END #

class Stack:
    def __init__(self):
        self.items = []
        
    def isEmpty(self):
        return self.items == []
        
    def push(self, item):
        self.items.insert(0,item)
        
    def pop(self):
        return self.items.pop(0)
        
    def peek(self, i):
        return self.items[i]
    
    def size(self):
        return len(self.items)    

stack = Stack()

class JSONRequestHandler (BaseHTTPRequestHandler):
    
    # GET METHOD return .json file #
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "application/json")
        self.wfile.write("\r\n")

        if self.path[1:] == "get_queue":
            i = 0
            self.wfile.write("{\n")
            while i < stack.size():
                self.wfile.write("\"" + str(i) + "\": {\n")
                self.wfile.write("\"champ_1\": \"")
                tmp = stack.peek(i).split('|')[0]
                if tmp != "":
                    self.wfile.write(tmp.split('/')[1].split('.')[0])
                else:
                    self.wfile.write(tmp)
                self.wfile.write("\",\n\"champ_2\": \"")
                tmp2 = stack.peek(i).split('|')[1]
                if tmp2 != "":
                    self.wfile.write(tmp2.split('/')[1].split('.')[0])
                else:
                    self.wfile.write(tmp2)
                self.wfile.write("\",\n\"champ_3\": \"")
                tmp3 = stack.peek(i).split('|')[2]
                if tmp3 != "":
                    self.wfile.write(tmp3.split('/')[1].split('.')[0])
                else:
                    self.wfile.write(tmp3)
                self.wfile.write("\",\n\"champ_4\": \"")
                tmp3 = stack.peek(i).split('|')[3]
                if tmp3 != "":
                    self.wfile.write(tmp3.split('/')[1].split('.')[0])
                else:
                    self.wfile.write(tmp3)
                self.wfile.write("\"\n}")
                i += 1
                if i < stack.size():
                    self.wfile.write(",\n")
                else:
                    self.wfile.write("\n")
            self.wfile.write("}")
                
        else:
            try:
                output = open(FILE_PREFIX + "/" + self.path[1:] + ".json", 'r').read()
            except Exception:
                output = "{\"error\": \"Could not find file " + self.path[1:] + ".json\"" + "}"
            self.wfile.write(output)
    # GET METHOD return .json file #
    
    # POST METHOD for client requesting something #
    def do_POST(self):
        request = self.path.split('?')[0]

        if request == "/add_queue":
            champ_1 = self.path.split('?')[1].split('&')[0].split('=')[1]
            if champ_1 != "null":
                champ_1 = CHAMP_PREFIX + champ_1 + ".cor"
            else:
                champ_1 = ""
            champ_2 = self.path.split('?')[1].split('&')[1].split('=')[1]
            if champ_2 != "null":
                champ_2 = CHAMP_PREFIX + champ_2 + ".cor"
            else:
                champ_2 = ""
            champ_3 = self.path.split('?')[1].split('&')[2].split('=')[1]
            if champ_3 != "null":
                champ_3 = CHAMP_PREFIX + champ_3 + ".cor"
            else:
                champ_3 = ""
            champ_4 = self.path.split('?')[1].split('&')[3].split('=')[1]
            if champ_4 != "null":
                champ_4 = CHAMP_PREFIX + champ_4 + ".cor"
            else:
                champ_4 = ""
            stack.push(champ_1 + "|" + champ_2 + "|" + champ_3 + "|" + champ_4 + "|--server")

        if request == "/refresh_queue":
            if not stack.isEmpty():
                cor_arg = stack.pop()
                new_fork=os.fork()
                if new_fork==0:
                    print("Forking server with PID: %d"%os.getpid())
                    call([EXECUTABLE, cor_arg.split('|')[0], cor_arg.split('|')[1],
                          cor_arg.split('|')[2], cor_arg.split('|')[3], cor_arg.split('|')[4]])
                    exit(1)

        response_code = 200
        self.send_response(response_code)
        self.wfile.write('Content-Type: application/json\r\n')
        self.wfile.write('Client: %s\r\n' % str(self.client_address))
        self.wfile.write('User-agent: %s\r\n' % str(self.headers['user-agent']))
        self.wfile.write('Path: %s\r\n' % self.path)        
        self.end_headers()
            
    # POST METHOD for client requesting something #

# START SERVER FOREVER #
server = HTTPServer(("192.168.1.73", PORT), JSONRequestHandler)
server.serve_forever()
