///////////////////////////////////////////////////////
// Assembler X   Codigo 1 (Encendido de Led)         //
///////////////////////////////////////////////////////

// Configuracion del PIC Fusses/////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma config FOSC = INTRC_NOCLKOUT // Bits de seleccion del Oscillator 
#pragma config WDTE = OFF            // Bits de Activador de temporizador de watchdog 
#pragma config PWRTE = OFF           // Bits para habilitar el Power up
#pragma config MCLRE = OFF           // El pin Master Clear es un reinicio externo opcional que se activa tirando del pin hacia abajo
#pragma config CP = OFF              // Bit para la proteccion del codigo
#pragma config CPD = OFF             // Data Code Protection bit
#pragma config BOREN = OFF           // Brown Out Reset Selection bits
#pragma config IESO = ON             // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON            // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF             // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)


#include <xc.h>

// Codigo principal
void main(void) {
    /////Configuracion de puertos y registros/////////////////////////////////////////////////////////////////////////////////////////////////////
    //Nota: 0x00, es en hexadecimal y lo usamos para colocar todos los bits del registro en 0
    ANSEL = 0X00;                // En el registro Ansel cambiamos su comportamiento de analogico a digital
    PORTA = 0X00;                // El PORTA es el registro que controla las entradas y salidas del puerto A
    TRISA = 0X00;                // El registro TRISA permite que el puerto A se utilice como entrada cuando sus bits son 1 y salida cuando sus bits son 0
    PORTA = 0B00000001;          // Mediante numeros binarios seleccionamos el bit 0 para que se encienda con una señal degital de 1
    asm("nop");                  // En esta instruccion esperamos un momento, que nos permite ver el estado de nuestros registros en la simulacion 
    return;                      // Fin del programa
}