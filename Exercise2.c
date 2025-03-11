#include <stdio.h> //Standard I/O library
float celcius_to_fahrenheit(float celcius){ //convert celcius to farenheit
    return celcius * 9/5 + 32; //Formula
}
float farenheit_to_celcius(float farenheit){ //convert farenheit to celcius
    return (farenheit - 32) * 5/9; //Formula
}
float celcius_to_kelvin(float celcius){ //convert celcius to kelvin
    return celcius + 273.15; //Formula
}
float kelvin_to_celcius(float kelvin){ //convert kelvin to celcius
    return kelvin - 273.15; //Formula
}
float kelvin_to_farenheit(float kelvin){ //convert kelvin to farenheit
    return celcius_to_fahrenheit(kelvin_to_celcius(kelvin)); //Formula
}
float fareinheit_to_kelvin(float farenheit){ //convert farenheit to kelvin
    return celcius_to_kelvin(farenheit_to_celcius(farenheit)); //Formula
}
void categorize_temperature(float celcius){ //categorize temperature
    if (celcius < 0){ //if temperature is less than 0
        printf("Temperature Category: Freezing temps!\n"); //print category
        printf("Weather Advisory: Wear a coat!\n"); //print advisory
    }
    else if (celcius < 10){ //So on and so forth
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Wear a hoodie and pants!\n");
    }
    else if (celcius < 20){
        printf("Temperature Category: Cool\n");
        printf("Weather Advisory: Wear a Jacket!\n");
    }
    else if (celcius < 32){
        printf("Temperature Category: Warmer\n");
        printf("Weather Advisory: T shirt and shorts will do\n");
    }
    else if (celcius < 40){
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Stay hydrated! Sleeveless top and shorts will help.\n");
    }
    else{ //if temperature is greater than 40C
        printf("Temperature Category: Insanely Hot!\n");
        printf("Weather Advisory: Find a pool, or find A/C!\n");
    }
}

int main(){
    float temp; //Initalize temperature variable
    int scale; //initalize what scale we are inputting
    int convert; //Initalize which scale we are converting to
    printf("Enter the temperature: "); //Prompt user for temperature
    scanf("%f", &temp); //enter temperature
    printf("Choose the current scale (1) Celcius (2) Fahrenheit (3) Kelvin: "); //Prompt user for what scale the temperature is in
    scanf("%d", &scale); //enter scale
    if(scale > 3 || scale < 1){ //edge case checking
        printf("Invalid scale\n"); //print error message
        return 0;
    }
    printf("Convert to (1) Celcius (2) Farenheit (3) Kelvin: "); //Prompt user for what scale to convert to
    scanf("%d", &convert); //enter scale to convert to
    if (convert > 3 || convert < 1){ //edge case checking
        printf("Invalid conversion\n"); //print error message
        return 0;
    }
    if(scale == 1){ //if scale is celcius
        if(convert == 1){ //convert from Celcius to Celcius (repeat)
            printf("%fC\n", temp); //no conversion
            categorize_temperature(temp); //print category
        }
        else if(convert == 2){ //convert from Celcius to Farenheit
            printf("%fF\n", celcius_to_fahrenheit(temp)); //print conversion
            categorize_temperature(temp); //print category
        }
        else if(convert == 3){ //convert from Celcius to Kelvin
            printf("%fK\n", celcius_to_kelvin(temp)); //print conversion
            categorize_temperature(temp); //print category
        }
        else{ //edge case checking
            printf("Invalid conversion\n"); //print error message
            return 0;
        }
    }
    else if(scale == 2){ //if scale is Fahrenheit
        if (convert==1){ //convert from Fahrenheit to Celcius
            printf("%fC\n", farenheit_to_celcius(temp)); //print conversion
            categorize_temperature(farenheit_to_celcius(temp)); //print category
        }
        else if(convert == 2){ //Fahrenheit to Fahrenheit (repeat)
            printf("%fF\n", temp); //no conversion
            categorize_temperature(farenheit_to_celcius(temp)); //print category
        }
        else if(convert == 3){ //convert from Fahrenheit to Kelvin
            printf("%fK\n", fareinheit_to_kelvin(temp)); //print conversion 
            categorize_temperature(farenheit_to_celcius(temp)); //print category
        }
        else{ //edge case checking
            printf("Invalid conversion\n"); //print error message
            return 0;
        }
    }
    else if(scale == 3){ //if scale is Kelvin
        if (convert==1){ //convert from Kelvin to Fahrenheit
            printf("%fF\n", kelvin_to_farenheit(temp));
            categorize_temperature(kelvin_to_celcius(temp));
        }
        else if(convert == 2){ //convert from Kelvin to Celcius
            printf("%fC\nC", kelvin_to_celcius(temp)); //Kelvin to Celcius
            categorize_temperature(kelvin_to_celcius(temp)); //print category
        }
        else if(convert == 3){ //Kelvin to Kelvin (repeat)
            printf("%fK\n", temp); //no conversion
            categorize_temperature(kelvin_to_celcius(temp)); //print category
        }
        else{ //edge case checking
            printf("Invalid conversion\n"); //print error message
            return 0;
        }
    }
    else{ //edge case checking
        printf("Invalid scale\n"); //print error message
        return 0;
    }
    return 0;//end program
}