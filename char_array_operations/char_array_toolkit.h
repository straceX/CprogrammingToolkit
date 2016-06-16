/*upper all alphabet characters*/
char *upper_string(char [], size_t );

/*lower all alphabet characters*/
char *lower_string(char [], size_t);

/*size of char array size*/
int sizeof_string(const char *);

/*Atom number via second parameter*/
int atom_number(const char *,const char );

/*Maximum tokens length by first parameter and second parameter is seperator*/
int max_word_length(const char *,const char);

typedef  struct Tokenizing_Property_Pair
{
   int max_atom_length;
   int atom_count;
}Tokenizing_Property;

/*SET sentence tokenization property*/
Tokenizing_Property *sentence_tokenization(const char *,const char );

/*Tokenizing sentence via seperator(second parameter)*/
char **separation_sentence_words(const char *,const char );

