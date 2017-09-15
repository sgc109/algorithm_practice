# -*- coding: utf8 -*-


# Help Function - 수정하지 말 것
def get_morse_code_dict():
    morse_code = {
        "A": ".-", "N": "-.", "B": "-...", "O": "---", "C": "-.-.", "P": ".--.", "D": "-..", "Q": "--.-", "E": ".",
        "R": ".-.", "F": "..-.", "S": "...", "G": "--.", "T": "-", "H": "....", "U": "..-", "I": "..", "V": "...-",
        "K": "-.-", "X": "-..-", "J": ".---", "W": ".--", "L": ".-..", "Y": "-.--", "M": "--", "Z": "--.."
    }
    return morse_code


# Help Function - 수정하지 말 것
def get_help_message():
    message = "HELP - International Morse Code List\n"
    morse_code = get_morse_code_dict()

    counter = 0

    for key in sorted(morse_code):
        counter += 1
        message += "%s: %s\t" % (key, morse_code[key])
        if counter % 5 == 0:
            message += "\n"

    return message


def is_help_command(user_input):
    global result
    wrong = ["help", "h"]
    if user_input.lower() in wrong :
        result = True
        return result

    else :
        result = False
        return result

def is_validated_english_sentence(user_input):
    global result
    result =[]
    user_input_low = user_input.lower()
    user_input_list = list(user_input_low)
    for i in user_input_list :
        if i in ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','.',',','!','?'] :
            result.append(i)
    if result == user_input_list :
        return True
    elif result != user_input_list :
        return False

def is_validated_morse_code(user_input):

    morse_code = {
            "A": ".-", "N": "-.", "B": "-...", "O": "---", "C": "-.-.", "P": ".--.", "D": "-..", "Q": "--.-", "E": ".",
            "R": ".-.", "F": "..-.", "S": "...", "G": "--.", "T": "-", "H": "....", "U": "..-", "I": "..", "V": "...-",
            "K": "-.-", "X": "-..-", "J": ".---", "W": ".--", "L": ".-..", "Y": "-.--", "M": "--", "Z": "--.."
        }
    result = []
    for i in morse_code.values():
        result.append(i)
    if user_input in result :
        return True
    else :
        return False


def get_cleaned_english_sentence(raw_english_sentence):
    global result
    for i in ['.',',','!','?'] :
        raw_english_sentence = raw_english_sentence.replace(i,"")
    raw_english_sentence=raw_english_sentence.strip()
    result = raw_english_sentence
    return result


def decoding_character(morse_character):
    global result
    morse_code_dict = get_morse_code_dict()
    for a,b in morse_code_dict.items():
        if b == morse_character :
            result = a
    return result

def encoding_character(english_character):
    global result
    morse_code_dict = get_morse_code_dict()
    for a,b in morse_code_dict.items():
        if a == english_character :
            result = b
    return result


def decoding_sentence(morse_sentence):
    global result
    morse_sentence = morse_sentence.split(' ')
    result = []
    for i in morse_sentence :
        if i == '' :
            result.append(' ')
        else :
            a = decoding_character(i)
            result.append(a)
    result = ''.join(result)
    return result


def encoding_sentence(english_sentence):
    cleaned = get_cleaned_english_sentence(english_sentence)
    global result
    result_1 = []
    result_2 = []
    for i in cleaned :
        result_1.append(i)
    for i in result_1 :
        if i == ' ':
            result_2.append('')
        else :
            a = encoding_character(i)
            result_2.append(a)
    result_2 = ' '.join(result_2)
    return result_2


def main():
    print("Morse Code Program!!")
    # ===Modify codes below=============
    while True :
        user_input = input('Input your message(H - Help, 0 - Exit): ')
        if user_input == '0' :
            break
        elif is_help_command(user_input) == True :
            print(get_help_message())
        elif is_validated_morse_code(user_input) == True :
            print(encoding_sentence(user_input))
        elif is_validated_english_sentence(user_input) == True :
            print(decoding_sentence(user_input))
        else :
            print('Wrong Input')



    # ==================================
    print("Good Bye")
    print("Morse Code Program Finished!!")

if __name__ == "__main__":
    main()