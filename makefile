# Permet de créer les dossier nécessaires dans build/
MKCWD= mkdir -p $(@D)


# les paramètres
FLAGS ?= -ansi \
		-pedantic \
		-Wall \
		-Werror \
		-std=c++11 \
		-Isrc/ \
		-g # infos de débugs 

CXX ?= g++

TARGET = trajet 

# Cherches tout les fichiers C++
CXXFILES = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp)

# Tout les fichiers dépendances des fichiers C++ (les dépendances sont les headers)
DFILES = $(patsubst src/%.cpp, build/%.d, $(CXXFILES))

# Les fichiers objets correspondants aux fichier C++
OFILES = $(patsubst src/%.cpp, build/%.o, $(CXXFILES))


main: trajet 

trajet: $(OFILES)
	@$(MKCWD)
	@echo " OUTPUT [ $@ ] $<"
	@$(CXX) -o $@ $^ $(FLAGS)


build/%.o: src/%.cpp
	@$(MKCWD)
	@echo " CXX    [ $@ ] $<"
# MMD et MP sont nécessaires pour générer les fichier de dépendances 
	@$(CXX) $(FLAGS) -MMD -MP $< -c -o $@ 

run: trajet 
	@./trajet 

check: trajet 
	@valgrind ./trajet
clean: 
	@rm -rf build/
	@rm -rf trajet

-include $(DFILES)