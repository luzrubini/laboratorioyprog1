#define Amoladora 1
#define Mezcladora 2
#define Taladro 3
#define Alquilado 4
#define Finalizado 5
typedef struct
{
    int id;
    int dni;
    char nombre[20];
    char apellido[20];
    char nombreApellido[40];
    int estado;
    int contador;
}eCliente;

typedef struct
{
    int idAlquiler;
    int idCliente;
    int equipo;
    int estadoAlquiler;
    char operador[30];
    float tiempoEstimado;
    float tiempoReal;
    int estado;
}eAlquiler;

/**
 * Da de alta a un cliente
 * @param estructura eCliente.
 * @param tamaño de la estructura entero.
 * @return cliente dado de alta.
 */
void altaCliente(eCliente[],int);
/**
 * Inicializa los estados de la estructura eCliente a 0.
 * @param estructura eCliente.
 * @param tamaño de la estructura entero.
 * @return estado del cliente en 0.
 */
void inicializarEstadoCliente(eCliente[],int);
/**
 * Inicializa los estados de la estructura eAlquiler a 0.
 * @param estructura eAlquiler
 * @param tamaño de la estructura entero.
 * @return estado del alquiler en 0.
 */
void inicializarEstadoAlquiler(eAlquiler[],int);
/**
 * Realiza un nuevo alquiler
 * @param estructura eCliente.
 * @param estructura eAlquiler.
 * @param tamaño de la estructura eCliente entero.
 * @param tamaño de la estructura eAlquiler entero.
 * @return nuevo alquiler dado de alta.
 */
void nuevoAlquiler(eCliente[],eAlquiler[],int,int);
/**
 * Muestra alquileres por cliente
 * @param estructura eCliente.
 * @param estructura eAlquiler.
 * @param tamaño de la estructura eCliente entero.
 * @param tamaño de la estructura eAlquiler entero.
 * @return lista de clientes con los equipo alquilados.
 */
void mostrarAlquilerPorCliente(eCliente[],eAlquiler[],int,int);
/**
 *
 * @param estructura eCliente.
 * @param estructura eAlquiler.
 * @param tamaño de la estructura eCliente entero.
 * @param tamaño de la estructura eAlquiler entero.
 * @return
 */
void informar(eCliente[],eAlquiler[],int,int);
/**
 * Inicializa clientes
 * @param estructura eCliente.
 * @return da de alta cinco clientes
 */
void inicializarCliente(eCliente[]);
/**
 * Inicializa alquileres
 * @param estructura eAlquiler
 * @return da de alta ocho alquileres
 */
void inicializarAlquiler(eAlquiler[],eCliente[]);
/**
 * Muestra un cliente
 * @param estructura eCliente.
 * @param tamaño de la estructura tipo entero.
 * @return el cliente junto a sus datos
 */
void mostrarCliente(eCliente[],int);
/**
 * Modifica nombre y apellido de un cliente
 * @param estructura eCliente.
 * @param tamaño de la estructura tipo entero.
 * @return el cliente junto a sus datos modificados
 */
void modificarCliente(eCliente[],int);
/**
 * Elimina un cliente
 * @param estructura eCliente.
 * @param tamaño de la estructura tipo entero.
 * @return el cliente dado de baja.
 */
void eliminarCliente(eCliente[],int);
void mostrarAlquiler(eAlquiler[],int);
void finAlquiler(eAlquiler[],eCliente[],int);
void clienteConMasReclamos(eCliente[],eAlquiler[],int);
