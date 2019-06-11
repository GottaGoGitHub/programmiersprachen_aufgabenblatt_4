# ifndef COLOR_HPP
# define COLOR_HPP
/* Unterschied Struct und Class:
sprachlich gesehen ist der einzige Unterschied, dass in Klassen public und private unterschieden werden
bei einem struct ist prinzipiell alles public.
Ein struct ist dazu da, um Informationen zu einem "Bündel" zusammenzufassen, 
wohingegen eine Klasse dazu da ist um etwas zu machen.
Sie ist dazu da um etwas zu modellieren
*/

struct rgb{
    //init with grey tone
    float r = 0.5f;
    float g = 0.5f;
    float b = 0.5f;
};

# endif // COLOR_HPP