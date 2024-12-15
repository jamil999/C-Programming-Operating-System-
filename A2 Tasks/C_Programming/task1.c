#include <stdio.h>

struct food_items{
    int quant;
    float unit_price;
};

int main() {
    struct food_items paratha;
    struct food_items vegetables;
    struct food_items water;
    int total_people;

    printf("Quantity Of Paratha: ");
    scanf("%d", &paratha.quant);

    printf("Unit Price: ");
    scanf("%f", &paratha.unit_price);

    printf("Quantity Of Vegetables: ");
    scanf("%d", &vegetables.quant);

    printf("Unit Price: ");
    scanf("%f", &vegetables.unit_price);

    printf("Quantity Of Mineral Water: ");
    scanf("%d", &water.quant);

    printf("Unit Price: ");
    scanf("%f", &water.unit_price);

    printf("Number of People: ");
    scanf("%d", &total_people);

    float total_amount = ((paratha.quant * paratha.unit_price) + (vegetables.quant * vegetables.unit_price) + (water.quant * water.unit_price));

    float per_person_pay = total_amount / total_people;

    printf("Individual people will pay: %.2f tk\n", per_person_pay);
    return 0;
}