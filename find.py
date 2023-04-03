import requests
from unidecode import unidecode

def get_pokemon_info(name):
    # Remove accents and replace hyphens and apostrophes with spaces
    name = unidecode(name).replace('-', ' ').replace('\'', ' ')
    
    response = requests.get(f"https://pokeapi.co/api/v2/pokemon/{name.lower()}")
    
    if response.status_code == 200:
        pokemon_info = response.json()
        abilities = [ability['ability']['name'] for ability in pokemon_info['abilities']]
        
        print(f"Name: {pokemon_info['name'].capitalize()}")
        print("Abilities:")
        for ability in abilities:
            print(f"- {ability.capitalize()}")
    else:
        print("Pokemon not found.")

pokemon_name = input("Enter the name of a Pokemon: ")

get_pokemon_info(pokemon_name)

