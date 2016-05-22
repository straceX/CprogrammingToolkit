
char *upper_string(char *, size_t );

char *lower_string(char *, size_t);

int sizeof_string(const char *);


typedef  struct Tokenizing_Property_Pair
{
   int max_atom_length;
   int atom_count;

}Tokenizing_Property;

int atom_number(const char *,const char );
int max_word_length(const char *,const char);
char ** separation_sentence_words(const char *,const char );

