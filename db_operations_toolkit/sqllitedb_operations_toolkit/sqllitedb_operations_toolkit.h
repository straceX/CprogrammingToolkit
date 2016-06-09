typedef struct SQLliteDB
{
    char *ptrDBurl;
    char *ptrTableName;
} sqllitedb;


sqllitedb *open_dbconnection();

int create_table();
int update_table();
int delete_table();

int insert_data();
int update_data();
int delete_data();


sqllitedb *close_dbconnection();






