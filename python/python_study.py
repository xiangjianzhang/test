def print_end():
    print("test")
    print("test 1 ", end=" ")
    print("end")

def print_pos():
    print(10,20, sep=":")

def print_file():
    print("hello world", file="./test")

def print_strstr():
    name="lily"
    age=18
    print("name is {} age {}".format(name,age))
def print_mutiple_line_string():
    str=''' "What's your name?," I asked.
            He said "Bond, James Bond." '''
    print(str)
def print_escape_sequence():
    str="hello \n\n, \'\'\'\'  escape sequence"
    print(str)

def print_raw_string():
    str=r'hello\n\\\\\ raw string'
    print(str)

def var_test():
    i = 5
    print(i)
    i = i + 1
    print(i)
    s = '''This is a multi-line string.
    This is the second line.'''
    print(s)

def logic_line_physic_line():
    i=5;print(i); #two logic line per one physic line
    i=5;
    print(i); #one logic line per one physic line
def power_of():
    x=5
    y=6
    print("x {} power of y {} equal {}".format(x,y,x**y))

def  divide_exactly():
    print("{} divide {} is {}".format(12, 4, 12 // 4))


def if_else_test():
    number = 23
    guess = int(input('Enter an integer : '))
    print(guess)
    if guess == number:
        print('Congratulations, you guessed it.')
        print('(but you do not win any prizes!)')
    elif guess < number:
        print('No, it is a little higher than that')
    else:
        print('No, it is a little lower than that')
    print('Done')

def while_test():
    number = 23
    running = True
    while running:
        guess = int(input('Enter an integer : '))
        if guess == number:
            print('Congratulations, you guessed it.')
            running = False
        elif guess < number:
            print('No, it is a little higher than that.')
        else:
            print('No, it is a little lower than that.')
    else:
        print('The while loop is over.')
    print('Done')
def for_test():
    for i in range(1, 5):
        print(i)
    else:
        print('The for loop is over')

def break_test():
    while True:
        got = input('enter command:')
        if got == 's':
            break
        else:
            print('loop')
    else:
        print('while done')

def funtion_default_para():
    def say(message, times=1):
        print(message * times)
    say('hello')
    say('hello', 5)


def keyword_parameter_test():
    def key_word(a = 1, b = 20, c = 30):
        print(a, b, c)
    key_word()
    key_word(b = 100)

def function_varargs_test():
    def function_varargs(a=5, *numbers, **phonebook):
        print('a', a)
        for single_item in numbers:
            print('single_item', single_item)
        for first_part, second_part in phonebook.items():
            print(first_part,second_part)
    print(function_varargs(10,1,2,3,Jack=1123,John=2231,Inge=1560))

g_var = 50
def global_test():
    global g_var
    print('g_var is', g_var)
    g_var = 2
    print('Changed global g_var to',g_var)

def return_test():
    def maximum(x, y):
        if x > y:
            return x
        elif x == y:
            return 'the numbers is the samse'
        else:
            return y
    print(maximum(2,3))
    print(maximum(2,2))

def docstring_test():
    def print_max(x, y):
        '''Print the muaximum numer in two number

        the two number must be integer'''
        x = int(x)
        y = int(y)
        if x > y:
            print(x, 'is maximum')
        else:
            print(y, 'is maximum')
    print_max(3, 5)
    print(print_max.__doc__)

def module_test_01():
    import sys

    print('The command line arguments are:')
    for i in sys.argv:
        print(i)

    print('\n\nThe PYTHONPATH is', sys.path, '\n')
def from_import_test():
    from math import sqrt
    print('Square root of 16 is', sqrt(16))

def module_name_test():
    print(__name__)
    if __name__ == '__main__':
        print('This program is being run by itself')
    else:
        print('I am being imported from another module')

def dir_function_test():
    import sys
    dir(sys)

def list_test():
    shoplist = ['apple', 'mango', 'carrot', 'banana']
    print(' I have ', len(shoplist), 'items to purchase')

    print('these items are:', end = ' ')
    for item in shoplist:
        print(item, end = ' ')
    
    print('\n I also have buy price.')
    shoplist.append('rice')
    print('my shopping list is now', shoplist)

    print(' I will sort my list now')
    shoplist.sort()
    print('sorted shopping list is', shoplist)


    print('the first item i will buy is', shoplist[0])
    olditem = shoplist[0]
    del shoplist[0]
    print('I bought the ', olditem)
    print('My shopping list is now', shoplist)


def tuple_test():
    zoo = ('python', 'elephant', 'penguin')
    print('Number of animals in the zoo is', len(zoo))
    new_zoo = 'monkey', 'camel', zoo
    print('Number of cages in the new zoo is', len(new_zoo))
    print('All animals in new zoo are', new_zoo)
    print('Animals brought from old zoo are', new_zoo[2])
    print('Last animal brought from old zoo is', new_zoo[2][2])
    print('Number of animals in the new zoo is',
    len(new_zoo)-1+len(new_zoo[2]))

def dict_test():
    ab = {
        'Swaroop': 'swaroop@swaroopch.com',
        'Larry': 'larry@wall.org',
        'Matsumoto': 'matz@ruby-lang.org',
        'Spammer': 'spammer@hotmail.com'
    }

    print("Swaroop's address is", ab['Swaroop'])
    del ab['Spammer']

    print('\nThere are {} contacts in the address-book\n'.format(len(ab)))


    for name, address in ab.items():
        print('contact {} at {}'.format(name,address))

    ab['Guido'] = 'guido@python.org'

    if 'Guido' in ab:
        print("\nGuido's address is ", ab['Guido'])
    else:
        print("Guido's address not in ab")
    print("done")

def sequence_test():
    # list 
    '''sequence:

    These represent finite ordered sets indexed by non-negative numbers. The built-in function len() returns the number of items of a sequence. When the length of a sequence is n, the index set contains the numbers 0, 1, …, n-1. Item i of sequence a is selected by a[i].

    Sequences also support slicing: a[i:j] selects all items with index k such that i <= k < j. When used as an expression, a slice is a sequence of the same type. This implies that the index set is renumbered so that it starts at 0.

    Some sequences also support “extended slicing” with a third “step” parameter: a[i:j:k] selects all items of a with index x where x = i + n*k, n >= 0 and i <= x < j.
    '''
    shoplist = ['apple', 'mango', 'carrot', 'banana']
    name = 'swaroop'
    # Indexing or 'Subscription' operation #
    print('Item 0 is', shoplist[0])
    print('Item 1 is', shoplist[1])
    print('Item 2 is', shoplist[2])
    print('Item 3 is', shoplist[3])
    print('Item -1 is', shoplist[-1])
    print('Item -2 is', shoplist[-2])
    print('Character 0 is', name[0])
    # Slicing on a list #
    print('Item 1 to 3 is', shoplist[1:3])
    print('Item 2 to end is', shoplist[2:])
    print('Item 1 to -1 is', shoplist[1:-1])
    print('Item start to end is', shoplist[:])
    print('characters 1 to 3 is', name[1:3])
    print('characters 2 to end is', name[2:])
    print('characters 1 to -1 is', name[1:-1])
    print('characters start to end is', name[:])

def str_mothods():
    name = 'Swaroop'
    if name.startswith('Swa'):
        print('Yes, the string starts with "Swa"')
    if 'a' in name:
        print('Yes, it contains the string "a"')
    if name.find('war') != -1:
        print('Yes, it contains the string "war"')
    delimiter = '_*_'
    mylist = ['Brazil', 'Russia', 'India', 'China']
    print(delimiter.join(mylist)) 
    print('___'.join(mylist))

str_mothods()

