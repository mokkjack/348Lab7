#include <stdio.h> //Standard I/O library
float celsius_to_fahrenheit(float celsius){ //convert celsius to farenheit
    return celsius * 9/5 + 32; //Formula
}
float farenheit_to_celsius(float farenheit){ //convert farenheit to celsius
    return (farenheit - 32) * 5/9; //Formula
}
float celsius_to_kelvin(float celsius){ //convert celsius to kelvin
    return celsius + 273.15; //Formula
}
float kelvin_to_celsius(float kelvin){ //convert kelvin to celsius
    return kelvin - 273.15; //Formula
}
float kelvin_to_farenheit(float kelvin){ //convert kelvin to farenheit
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin)); //Formula
}
float fareinheit_to_kelvin(float farenheit){ //convert farenheit to kelvin
    return celsius_to_kelvin(farenheit_to_celsius(farenheit)); //Formula
}
void categorize_temperature(float celsius){ //categorize temperature
    if (celsius < 0){ //Extreme cold temps
        printf("Temperature Category: Freezing temps!\n"); //print category
        printf("Weather Advisory: Wear a coat!\n"); //print advisory
    }
    else if (celsius < 10){
        printf("Temperature Category: Cold\n");
        printf("Weather Advisory: Wear a Jacket!\n");
    }
    else if (celsius < 25){
        printf("Temperature Category: Comfortable\n");
        printf("Weather Advisory: T shirt and shorts will do!\n");
    }
    else if (celsius < 35){
        printf("Temperature Category: Hot\n");
        printf("Weather Advisory: Wear a sleeveless top and shorts.\n");
    }
    else{ //if temperature is greater than 40C
        printf("Temperature Category: Insanely Hot!\n");
        printf("Weather Advisory: Find A/C and stay hydrated!\n");
    }
}
int main(){
    float temp; //Initalize temperature variable
    int scale; //initalize what scale we are inputting
    int convert; //Initalize which scale we are converting to
    
    //copilot used to help with clearing the buffer
    while(1){ //Choose temperature float value until user inputs a valid number
        printf("Enter the temperature: "); //Prompt user for temperature
        if (scanf("%f", &temp) == 1) { // Check if input is a number and not some other character
            break; //end loop, move to next
        }
        printf("Invalid temperature input!\n"); //Print error message
        while (getchar() != '\n'); //Clear buffer and try again
    }
    while (1){ //Choose scale of temperature until user inputs valid number
        printf("Choose the current scale (1) Celsius (2) Fahrenheit (3) Kelvin: "); //Prompt user for what scale the temperature is in
        if (scanf("%d", &scale) == 1 && scale>=1 && scale<=3){ //edge case checking and make sure input is a number
            break; //end loop
        }
        printf("Invalid scale choice\n"); //print error message
        while (getchar() != '\n'); //Clear buffer
        }
    if (scale==3){ //used to check if negative kelvin
        while (temp<0){ //while the temp is less than 0
            printf("Invalid temperature input. Kelvin can not be less than 0\n"); //Print error Message
            if (scanf("%f", &temp) == 1 && temp>=0) { // Check if input is not a number
                    break; //end loop
            }
            printf("Invalid temperature input. Kelvin can not be less than 0\n"); //Print error message
            while (getchar() != '\n'); //Clear buffer
            }
        }
    while (1){ //Scale to convert to, until user inputs a valid number
        printf("Convert to (1) Celsius (2) Farenheit (3) Kelvin: "); //Prompt user
        if (scanf("%d", &convert) == 1 && convert>=1 && convert<=3){ //edge case checking
            break; //end loop and move to next
        }
        printf("Invalid conversion choice\n"); //print error message
        while (getchar() != '\n'); //Clear buffer
    }
    if(scale == 1){ //if scale is celsius
        if(convert == 1){ //convert from Celsius to Celsius (repeat)
            printf("%fC\n", temp); //no conversion
            categorize_temperature(temp); //print category
        }
        else if(convert == 2){ //convert from Celsius to Farenheit
            printf("%fF\n", celsius_to_fahrenheit(temp)); //print conversion
            categorize_temperature(temp); //print category
        }
        else if(convert == 3){ //convert from Celsius to Kelvin
            printf("%fK\n", celsius_to_kelvin(temp)); //print conversion
            categorize_temperature(temp); //print category
        }
        else{ //edge case checking
            printf("Invalid conversion\n"); //print error message
            return 0;
        }
    }
    else if(scale == 2){ //if scale is Fahrenheit
        if (convert==1){ //convert from Fahrenheit to Celsius
            printf("%fC\n", farenheit_to_celsius(temp)); //print conversion
            categorize_temperature(farenheit_to_celsius(temp)); //print category
        }
        else if(convert == 2){ //Fahrenheit to Fahrenheit (repeat)
            printf("%fF\n", temp); //no conversion
            categorize_temperature(farenheit_to_celsius(temp)); //print category
        }
        else if(convert == 3){ //convert from Fahrenheit to Kelvin
            printf("%fK\n", fareinheit_to_kelvin(temp)); //print conversion 
            categorize_temperature(farenheit_to_celsius(temp)); //print category
        }
        else{ //edge case checking
            printf("Invalid conversion\n"); //print error message
            return 0;
        }
    }
    else if(scale == 3){ //if scale is Kelvin
        if (convert==1){ //convert from Kelvin to Celsius
            printf("%fC\n", kelvin_to_celsius(temp)); //Kelvin to Celsius
            categorize_temperature(kelvin_to_celsius(temp)); //print category
        }
        else if(convert == 2){ //convert from Kelvin to Farenheight
            printf("%fF\n", kelvin_to_farenheit(temp));
            categorize_temperature(kelvin_to_celsius(temp));
        }
        else if(convert == 3){ //Kelvin to Kelvin (repeat)
            printf("%fK\n", temp); //no conversion
            categorize_temperature(kelvin_to_celsius(temp)); //print category
        }
        else{ //edge case checking
            printf("Invalid conversion\n"); //print error message
            return 0;
        }
    }
    return 0;//end program
}