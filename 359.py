class Logger:

    def __init__(self):
        self.hash_map = {}

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        a = self.hash_map.get(message)
        if a == None or a + 10 <= timestamp:
            self.hash_map[message] = timestamp
            return True
        else:
            return False
            

# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)