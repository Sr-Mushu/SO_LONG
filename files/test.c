#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_map_format(char **map, int m_height) {
    if (m_height < 3) {
        return false;
    }

    // Verifica a primeira linha
    char *first_line = map[0];
    int i = 0;
    while (first_line[i] != '\n') {
        if (first_line[i] != '1') {
            return false;
        }
        i++;
    }

    // Verifica as linhas intermediárias
    i = 1;
    while (i < m_height - 1) {
        if (map[i][0] != '1' || map[i][strlen(map[i]) - 2] != '1') {
            return false;
        }
        i++;
    }

    // Verifica a última linha
    char *last_line = map[m_height - 1];
    int last_line_length = strlen(last_line);
    if (last_line[last_line_length - 2] != '1') {
        return false;
    }

    return true;
}

int main() {
    char *map1[] = {
        "111111111111111111111111111\n",
        "1P110000C0C0000000000000C11\n",
        "101110111111100011111011011\n",
        "1000000000000000C0000011111\n",
        "101110111111101111110000001\n",
        "1011100000C0110100010111111\n",
        "10000001010010110001000CCC1\n",
        "1C110011E110100010001111C11\n",
        "111111111111111111111111111\n",
        "\n",
        "\n"
    };

    char *map2[] = {
        "111111111111111111111111111\n",
        "1P110000C0C0000000000000C11\n",
        "101110111111100011111011011\n",
        "1000000000000000C0000011111\n",
        "101110111111101111110000001\n",
        "1011100000C0110100010111111\n",
        "10000001010010110001000CCC1\n",
        "1C110011E110100010001111C11\n",
        "111111111111111111111111111"
    };

    int m_height1 = sizeof(map1) / sizeof(map1[0]);
    int m_height2 = sizeof(map2) / sizeof(map2[0]);

    bool is_valid1 = is_valid_map_format(map1, m_height1);
    if (is_valid1) {
        printf("O formato do mapa 1 é válido!\n");
    } else {
        printf("O formato do mapa 1 não é válido!\n");
    }

    bool is_valid2 = is_valid_map_format(map2, m_height2);
    if (is_valid2) {
        printf("O formato do mapa 2 é válido!\n");
    } else {
        printf("O formato do mapa 2 não é válido!\n");
    }

    return 0;
}