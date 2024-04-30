#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;
typedef struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} Cliente;

float calcular_costo(Producto *producto);
int main()
{
    srand(time(0));
    int nClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &nClientes);
    Cliente *clientes = (Cliente *)malloc(nClientes * sizeof(Cliente));
    for (int i = 0; i < nClientes; i++)
    {
        clientes[i].ClienteID = i + 1;
        clientes[i].NombreCliente = (char *)malloc(100 * sizeof(char));
        printf("ingrese el nombre del cliente %d: ", i + 1);
        scanf("%s", clientes[i].NombreCliente);
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;
        clientes[i].Productos = (Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = (rand() % 91 + 10) / 1.0;
        }
    }
    //** mostrar
    float total_pagar;
    for (int i = 0; i < nClientes; i++)
    {
        total_pagar = 0;
        printf("Cliente %d: %s\n", clientes[i].ClienteID, clientes[i].NombreCliente);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("Producto %d: %s, Cantidad: %d, Precio Unitario: %.2f\n", clientes[i].Productos[j].ProductoID, clientes[i].Productos[j].TipoProducto, clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].PrecioUnitario);
            total_pagar += calcular_costo(&clientes[i].Productos[j]);
        }
        printf("Total a pagar es: %.2f\n", total_pagar);
    }
    for (int i = 0; i < nClientes; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos); 
    }
    free(clientes);

    return 0;
}
float calcular_costo(Producto *producto)
{
    return producto->Cantidad * producto->PrecioUnitario;
}
