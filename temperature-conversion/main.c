

#include <stdio.h>
#include <ctype.h>



// Required functions
float celsius_to_fahrenheit(float celsius){ return 9*celsius/5 + 32; }
float fahrenheit_to_celsius(float fahrenheit){ return 5*(fahrenheit-32)/9; }
float celsius_to_kelvin(float celsius){ return celsius + 273.15; }
float kelvin_to_celsius(float kelvin){ return kelvin - 273.15; }
void categorize_temperature(float celsius)
{
    if(celsius < 0){
        printf("Freezing! Wear a coat.\n");
    }else if(0 <= celsius && celsius < 10){
        printf("Cold! Wear a jacket.\n");
    }else if(10 <= celsius && celsius < 25){
        printf("Comfortable! Go outside.\n");
    }else if(25 <= celsius && celsius <= 35){
        printf("Hot! Wear shorts.\n");
    }else{
        printf("Extreme Heat! Suffer.\n");
    }
}

void clear_input_buffer(){ while(getchar() != '\n'); }
// Returns 1 if validated, 0 if error
int validate_temp(float celsius)
{
    // Absolute 0
    if(celsius < -273.15) return 0;
    // Most materials in most situations 
    // are vaporized by 10,000 kelvin
    if(celsius > 9726.85) return 0;
    
    return 1;
}
float get_temp(char scale)
{
    int isInputValid;
    float input;
    do{
        isInputValid = 1;

        // Prompt the user
        printf("Input Temperature: ");
        scanf("%f", &input);
        clear_input_buffer();

        // Convert to celsius
        switch(scale)
        {
            case 'c':
                break;
            case 'f':
                input = fahrenheit_to_celsius(input);
                break;
            case 'k':
                input = kelvin_to_celsius(input);
                break;
        }

        // Validate
        isInputValid = validate_temp(input);
        if(!isInputValid) printf("Error: Input is invalid, please try again\n");

    }while(!isInputValid);
    return input;
}
char get_scale()
{
    int isInputValid;
    char input;
    do{
        isInputValid = 1;

        // Prompt the user
        printf("Celsius - c   Fahrenheit - f   Kelvin - k\nSelect Scale: ");
        input = getchar();
        clear_input_buffer();

        // Normalize input
        input = tolower(input);

        // Validate
        if(input != 'c' && input != 'f' && input != 'k'){
            printf("Error: Input is invalid, please try again\n");
            isInputValid = 0;
        }

    }while(!isInputValid);
    return input;
}
char get_target_scale(char scale)
{
    int isInputValid;
    char input;
    do{
        isInputValid = 1;

        // Prompt the user
        printf("Celsius - c   Fahrenheit - f   Kelvin - k\nSelect Target Scale: ");
        input = getchar();
        clear_input_buffer();

        // Normalize input
        input = tolower(input);

        // Validate input
        if(input != 'c' && input != 'f' && input != 'k'){
            printf("Error: Input is invalid, please try again\n");
            isInputValid = 0;
        }else if(input == scale){
            printf("Error: Cannot convert %c to %c\n", scale, input);
            isInputValid = 0;
        }

    }while(!isInputValid);
    return input;
}

int main()
{
    float temp, result;
    char scale, target_scale;

    // Prompt user for input
    scale = get_scale();
    target_scale = get_target_scale(scale);
    temp = get_temp(scale);

    // Convert to target scale
    switch(target_scale)
    {
        case 'c':
            result = temp;
            break;
        case 'f':
            result = celsius_to_fahrenheit(temp);
            break;
        case 'k':
            result = celsius_to_kelvin(temp);
            break;
        default:
            printf("Error: An unexpected error occured, please try again.\n");
            return 1;
    }

    // Interpret the result
    printf("\nResults:\n%.2f%c\n", result, target_scale);
    categorize_temperature(temp);

    return 0;
}