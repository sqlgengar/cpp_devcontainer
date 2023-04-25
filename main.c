#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRIME 20

typedef struct 
{ 
    int index;
    int prime_number;
} Register;

void init_register( Register[] );
int generate_random_number();
int is_prime( int );
bool is_repeat( Register[], int );
void fill_unique_primes( Register[], int, int* );
void write_file_binary( Register[], int );
void main_system();
void printr( Register[] );
void write_file( Register[], char* );
void printb();
void load_binari( Register[] );
// BOGOSORT!!!
void sort_primes( Register[] );
void print_bogosort( Register[] );

int main()
{
    main_system();

    return 0;
}

void main_system()
{
    Register prime_numbers[MAX_PRIME];
    Register prime_loaded[MAX_PRIME];
    int new_number;
    int index_writed = 0;
    char *path_binari = "./estructura_db/practice_c/_files/binari_primes.dat";
    char *path_binari_sorted = "./estructura_db/practice_c/_files/binari_primes_sorted.dat";

    init_register( prime_numbers );
    
    do
    {
        new_number = generate_random_number();

        fill_unique_primes( prime_numbers, new_number, &index_writed );
    }while( index_writed <= 20 );
    printr( prime_numbers );

    write_file( prime_numbers, path_binari );
    printb();

    load_binari( prime_loaded );
    printr( prime_loaded );

    sort_primes( prime_loaded );
    write_file( prime_loaded, path_binari_sorted );
}

void init_register( Register init_prime_numbers[MAX_PRIME] )
{
    for( int i = 0; i < MAX_PRIME; i++ )
    {
        init_prime_numbers->index =         i+1;
        init_prime_numbers->prime_number =  0;
    }
}

int generate_random_number()
{
    int temp_random_number;
    bool prime;

    srand( time(NULL) );

    do
    {
        temp_random_number = rand() % 200;

        prime = is_prime( temp_random_number );
    } while( !prime );

    return temp_random_number;
}

int is_prime( int random_number )
{
    if( random_number <= 1 )
    {
        return false;
    }

    for( int i = 2; i * i <= random_number; i++)
    {
        if ( random_number % i == 0 )
        {
            return false;
        }
    }

    return true;
}

void fill_unique_primes( Register prime_array[MAX_PRIME], int value_prime, int* index )
{
    if( !is_repeat( prime_array, value_prime ) )
    {
        prime_array[(*index)].prime_number =    value_prime;
        prime_array[(*index)].index =           (*index);
        (*index)++;
    }
}

bool is_repeat( Register check_primes[MAX_PRIME], int prime )
{
    for( int i = 0; i < MAX_PRIME; i++ )
    {
        if( check_primes[i].prime_number == prime ) return true;
    }
    
    return false;
}

void printr( Register data[MAX_PRIME] )
{
    printf( "\t INDEX \t | \t PRIME \n" );

    for( int i = 0; i < MAX_PRIME; i++ )
    {
        printf( "\t %d \t - \t %d \n", data[i].index, data[i].prime_number );
    }
}

void write_file( Register write_primes[MAX_PRIME], char* path_file )
{
    FILE *file;

    file = fopen( path_file, "wb+" );

    fseek( file, 0L, SEEK_END );
    fwrite( write_primes, sizeof(write_primes), MAX_PRIME, file );

    fclose(file);
}

void printb()
{
    Register data_file;
    FILE *file;
    char *path = "./estructura_db/practice_c/_files/binari_primes.dat";

    file = fopen( path, "rb+" );

    printf( "\t INDEX \t | \t PRIME \n" );
    fseek( file, 0L, SEEK_SET );
    fread( &data_file, sizeof(data_file), 1, file );

    while( !feof(file) )
    {
        printf( "\t %d \t - \t %d \n", data_file.index, data_file.prime_number );
        fread( &data_file, sizeof(data_file), 1, file );
    }

    fclose(file);
}

void load_binari( Register data_binari[MAX_PRIME] )
{
    FILE *file;
    char *path = "./estructura_db/practice_c/_files/binari_primes.dat";

    file = fopen( path, "rb+" );

    fseek( file, 0L, SEEK_SET );
    fread( data_binari, sizeof(data_binari), MAX_PRIME, file );

    fclose(file);
}

// BOGOSORT!!!
void sort_primes( Register prime_loaded[MAX_PRIME] )
{
    Register temp_register;
    bool is_sorted = true;

    do
    {
        for( int i=0; i < MAX_PRIME; i++ )
        {
            int index_rand = rand() % MAX_PRIME;

            temp_register = prime_loaded[i];
            prime_loaded[i] = prime_loaded[index_rand];
            prime_loaded[index_rand] = temp_register;
        }

        for ( int j = 0; j < MAX_PRIME; j++)
        {
            if( prime_loaded[j].prime_number > prime_loaded[j+1].prime_number )
            {
                is_sorted = false;
                break;
            }
        }
    
    print_bogosort( prime_loaded );

    }while( !is_sorted );
}

void print_bogosort( Register data[MAX_PRIME] )
{
    system("clear");
    for( int i = 0; i < MAX_PRIME; i++)
    {
        printf("%d", i);
        for( int j = 0; j < data[i].prime_number; j++)
        {
            printf("-");
        }
        printf("\n");
    }
    printf("#########################################################################################\n");
    system("sleep 1");
}