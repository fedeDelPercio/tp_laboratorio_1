#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;



/** \brief Muestra el menu en pantalla y selecciona opcion por el usuario
 *
 * \return Devuelve opcion seleccionada por el usuario
 *
 */
int menu();


/**
 * \brief Incicializa el estado de las variables a cero
 *
 * \param array
 * \param cantidad de personas
 */
void inicializarPersonas(EPersona[], int );


/** \brief Buscamos lugar libre para escribir datos sobre persona
 *
 * \param array
 * \param cantidad de personas
 * \return Devuelve lugar libre o mensaje de error
 */
int buscarLibre(EPersona[], int );

/** \brief Buscamos persona mediante dni
 *
 * \param array
 * \param cantidad de personas
 * \param numero de dni
 * \return Devuelve numero de lugar libre
 *
 */
int buscarPersona(EPersona[], int , int);

/** \brief Se da de alta persona ingresada
 *
 * \param array
 * \param cantidad de personas
 * \return
 *
 */
void altaPersona(EPersona[], int );

/** \brief Mostramos una persona en pantalla
 *
 * \param  una persona
 */
void mostrarPersona(EPersona );

/** \brief Mostramos todas las personas en pantalla
 *
 * \param array
 * \param cantidad de personas
 *
 */
void mostrarPersonas(EPersona[], int);

/** \brief Se le da de baja cambiandole el estado a la persona
 *
 * \param array
 * \param cantidad de personas
 *
 */
void bajaPersona(EPersona[], int );

/** \brief Ordena personas alfabeticamente
 *
 * \param array
 *
 */
void ordenarPersona(EPersona[]);

/** \brief Graficamos por edad a las personas ingresadas
 *
 * \param array
 *
 */
int graficoPersonas(EPersona[]);


#endif // FUNCIONES_H_INCLUDED
