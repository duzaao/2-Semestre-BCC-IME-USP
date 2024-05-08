import string

# The Cipher-text
Y = ['10101', '00100', '10101', '01011', '11001', '00011', '01011', '10101', '00100', '11001', '11010']
# Parse to binary value
y = list(map(lambda v: int(v, 2), Y))

max_val = 32
alphabet_size = 26

# decrypt([0b11111, ...]) = [(key=0b1111, decrpyted=[0b11111, ...]), ...]
def decrypt(encrypted):
    possible_keys = range(max_val)
    attempt = []
    for key in possible_keys:
        decrypted = []
        for symbol in encrypted:
            # XOR is equivalent to Add in GF(2)
            # If not GF(2), add then wrap around using modulo
            v = symbol ^ key & (max_val - 1)
            print('v = %d' % v)
            if v > alphabet_size:
                break
            decrypted.append(v)
        if len(decrypted) < len(encrypted):
            print('bad key %d' % key)
            continue
        print('good key %d' % key)
        attempt.append((key, decrypted))
    return attempt

# alphabet plus a space
alph = list(string.ascii_lowercase)
alph.append(' ')
def decode(encoded):
    return ''.join(map(lambda x: alph[x], encoded))

results = decrypt(y)

for (key, encoded) in results:
    decoded = decode(encoded)
    print(decoded)