#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

// Function to convert hexadecimal color to single integer
long hex_to_long(char *hex) {
    return strtol(hex, NULL, 16);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char choice;
    char fog_color_hex[8], sky_color_hex[8], water_color_hex[8], water_fog_color_hex[8], grass_color_hex[8], foliage_color_hex[8];
    long fog_color, sky_color, water_color, water_fog_color, grass_color, foliage_color;

    do {
        // Prompt user for color values in hexadecimal
        printf("Minecraft Biome Colour Generator\n");
        printf("*********************************\n");
        printf("Use colors-picker.com or another online colour picker to choose hex colours)\n");
        printf("Enter fog color in hex (e.g., #ffffff): ");
        scanf("%s", fog_color_hex);
        printf("Enter sky color in hex (e.g., #ffffff): ");
        scanf("%s", sky_color_hex);
        printf("Enter water color in hex (e.g., #ffffff): ");
        scanf("%s", water_color_hex);
        printf("Enter water fog color in hex (e.g., #ffffff): ");
        scanf("%s", water_fog_color_hex);
        printf("Enter grass color in hex (e.g., #ffffff): ");
        scanf("%s", grass_color_hex);
        printf("Enter foliage color in hex (e.g., #ffffff): ");
        scanf("%s", foliage_color_hex);

        // Convert hexadecimal color strings to long integers
        fog_color = hex_to_long(&fog_color_hex[1]);
        sky_color = hex_to_long(&sky_color_hex[1]);
        water_color = hex_to_long(&water_color_hex[1]);
        water_fog_color = hex_to_long(&water_fog_color_hex[1]);
        grass_color = hex_to_long(&grass_color_hex[1]);
        foliage_color = hex_to_long(&foliage_color_hex[1]);

        // Prompt user for filename
        printf("Enter filename (without extension): ");
        scanf("%s", filename);

        // Create and write JSON file
        FILE *fp;
        char filepath[MAX_FILENAME_LENGTH + 25]; // Length of "output/data/Biome_colours/worldgen/biome"
        sprintf(filepath, "output/data/biome_colours/worldgen/biome/%s.json", filename);
        fp = fopen(filepath, "w");
        if (fp == NULL) {
            printf("Error creating JSON file.\n");
            return 1;
        }
        fprintf(fp, "{\n");
        fprintf(fp, "  \"carvers\": {\n");
        fprintf(fp, "    \"air\": [\n");
        fprintf(fp, "      \"minecraft:cave\",\n");
        fprintf(fp, "      \"minecraft:cave_extra_underground\",\n");
        fprintf(fp, "      \"minecraft:canyon\"\n");
        fprintf(fp, "    ]\n");
        fprintf(fp, "  },\n");
        fprintf(fp, "  \"downfall\": 0.5,\n");
        fprintf(fp, "  \"effects\": {\n");
        fprintf(fp, "    \"fog_color\": %ld,\n", fog_color);
        fprintf(fp, "    \"sky_color\": %ld,\n", sky_color);
        fprintf(fp, "    \"water_color\": %ld,\n", water_color);
        fprintf(fp, "    \"water_fog_color\": %ld,\n", water_fog_color);
        fprintf(fp, "    \"grass_color\": %ld,\n", grass_color);
        fprintf(fp, "    \"foliage_color\": %ld\n", foliage_color);
        fprintf(fp, "  },\n");
        fprintf(fp, "  \"features\": [\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    [],\n");
        fprintf(fp, "    []\n");
        fprintf(fp, "  ],\n");
        fprintf(fp, "  \"has_precipitation\": true,\n");
        fprintf(fp, "  \"spawn_costs\": {},\n");
        fprintf(fp, "  \"spawners\": {\n");
        fprintf(fp, "    \"ambient\": [],\n");
        fprintf(fp, "    \"axolotls\": [],\n");
        fprintf(fp, "    \"creature\": [],\n");
        fprintf(fp, "    \"misc\": [],\n");
        fprintf(fp, "    \"monster\": [],\n");
        fprintf(fp, "    \"underground_water_creature\": [],\n");
        fprintf(fp, "    \"water_ambient\": [],\n");
        fprintf(fp, "    \"water_creature\": []\n");
        fprintf(fp, "  },\n");
        fprintf(fp, "  \"temperature\": 0.8\n");
        fprintf(fp, "}\n");
        fclose(fp);

        printf("JSON file created successfully.\n");

        // Prompt user to create another JSON file
        printf("Do you want to create another JSON file? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
