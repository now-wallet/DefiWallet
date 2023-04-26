class NowError(Exception):
    INVALID_REQUEST = -32600
    UNKNOWN_METHOD = -32601
    BAD_PARAMETERS = -32602
    INTERNAL_ERROR = -32603
    USER_CANCELLED = -32000
    PROTOCOL_ERROR = -32001
    HW_LOCKED = -32002
    NETWORK_MISMATCH = -32003
    
    def __init__(self, code, message, data):
        self.code = code
        self.message = message
        self.data = data

    def __str__(self):
        return repr(self)