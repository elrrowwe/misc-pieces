import pygame
import random
import PySimpleGUI as sg
import keyboard

"""
This is a simple script I wrote for studying for a physics exam. from the list of questions it randomly picks 4 (indices) and displays them 
on a pygame window. The user can also display the question text in a new PySimpleGUI window. 
"""

pygame.init()

window_width, window_height = 1000, 800

mint_green = (152, 255, 152)
black = (0, 0, 0)
white = (255, 255, 255)

questions_dict = {
    1:'Nabla operator and it`s applications to scalar, vector fields.',
    2:'Electromagnetic waves and light, velocity of light in vacuum and transparent materials, Poynting`s vector.',
    3:'The Huygens principle: its applications to rectilinear propagation of light, reflection and refraction.',
    4:'The Fermat`s principle: its application to reflection and refraction.',
    5:'Propagation of light in inhomogeneus media -- explanation of mirages.',
    6:'Interference -- explanation and formulas for constructive and destructive interference, interference in thin films, double slit interference.',
    7:'Diffraction gratings: condition for diffraction fringes (derivation), dispersion of a grating and resolving power of a grating.',
    8:'Bragg law: diffraction of X-rays on crystals, derivation of the formula.',
    9:'Polarization and circular polarization. Law of Malus. Polarization by reflection, Brewster`s angle.',
    10:'Dual character of light: proofs of both wave and corpuscular nature of light with explanations.',
    11:'Thermal radiation: Wien`s law, Stefan-Boltzmann law, plots with explanations.',
    12:'Photoelectric effect: description of the experiment, explanation using the work function.',
    13:'Wave behavior of particles: de Broglie hypothesis, experimental proofs.',
    14:'Structure of the hydrogen atom: Bohr model, Bohr postulates, Arguments for validity/invalidity of the model.',
    15:'1-D, time invariant Schroedinger`s equation. Interpretation of the wave function.',
    16:'Wave mechanics.',
    17:'Particle in potential well -- according to classical and modern physics.',
    18:'Heisenberg`s uncertainty principle, both forms: position-momentum and time-energy, explained.',
    19:'The Pauli exclusion principle: application to fermions (and what fermions are), the explanation of elements properties in the periodic table.',
    20:'Bonds in solids: explanation of ionic, covalent, hydrogen and van der Waals bonds.',
    21:'Electrical conduction of solids: band theory of solids, explanation of bands and band-gap value, doping -- donors and acceptors, n-type and p-type semiconductors. Fermi level in semiconductors.',
    22:'Semiconductors: what they are, explanation according to the band theory of solids.',
    23:'Radioactive decay law (+ formula derivation): half-life time, carbon dating.',
    24:'Fission and fusion: when can they be exothermic?',
    25:'Michelson-Morley experiment: Einstein`s postulates of special relativity.',
    26:'Time dilation -- derivation of the formula.',
    27:'Length contraction -- derivation of the formula.',
    28:'Lorentz transformation of coordinates.',
    29:'Lorentz transformation of velocities -- derivation, application to addition of velocities.'
}

window = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption("Physics exam questions :0")

window.fill(mint_green)

square_size = 200
space_between_squares = 20
start_x = (window_width - (square_size * 4) - (space_between_squares * 3)) // 2
start_y = (window_height - square_size) // 2

numbers = []

#generating random numbers + drawing them in the rectangles 
def generate_new_numbers():
    window.fill(mint_green)
    numbers.clear()

    for i in range(4):
        x = start_x + (i * (square_size + space_between_squares))
        y = start_y
        pygame.draw.rect(window, black, (x, y, square_size, square_size))

        number = random.randint(1, 29)
        while number in numbers:
            number = random.randint(1, 29)

        numbers.append(number)

        font = pygame.font.Font(None, 70)
        number_text = font.render(str(number), True, mint_green)
        number_text_rect = number_text.get_rect(center=(x + square_size // 2, y + square_size // 2))
        window.blit(number_text, number_text_rect)

#displaying the question text in a new PySimpleGUI window
def display_question(key):
    sg.theme('GreenTan')
    layout = [[sg.Text(f'{questions_dict[key]}', font=('Arial', 20))]]      
    sgwin = sg.Window(f'Question {key}', layout)    

    while True:                             
        event, values = sgwin.read()        
        if event == sg.WIN_CLOSED or event == 'Exit':
            break
        elif event == '<space>' or event == '<Return>' or event == '<Escape>':
            sgwin.close()
            break               
        
 
generate_new_numbers()

pygame.display.update()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
            generate_new_numbers()
            pygame.display.update()

        #tracking what key has been pressed in order to display the question, corresponding to the number on the square
        #eg let the first square have the number 8 on it, then pressing the key 1 will display question number 8 etc. 
        elif event.type == pygame.KEYDOWN and event.key == pygame.K_1:
            display_question(numbers[0])
        elif event.type == pygame.KEYDOWN and event.key == pygame.K_2:
            display_question(numbers[1])
        elif event.type == pygame.KEYDOWN and event.key == pygame.K_3:
            display_question(numbers[2])
        elif event.type == pygame.KEYDOWN and event.key == pygame.K_4:
            display_question(numbers[3])
        
        pygame.display.update()
            

pygame.quit()
