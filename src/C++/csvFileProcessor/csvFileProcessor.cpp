#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <string.h>


void processCsv(const char csv[], const char selectedColumns[], const char filters[]) {
        //separando linhas e colunas
        std::vector<std::string> columns;
        char *csvCopy = strdup(csv);
        std::vector<std::vector<std::string>> lines;
        char *lines_token = strtok(csvCopy, "\n");

        while (lines_token != NULL) {
          char *column_token = strtok(lines_token, ",");
          while (column_token != NULL) {
            columns.push_back(std::string(column_token));
            column_token = strtok(NULL, ",");
          }
        lines.push_back(columns);
        lines_token = strtok(NULL, "\n");
        }

        

    free(csvCopy);

    //formatando filtros
    std::vector<std::string> filtersArr;
    char *filters_cpy = strdup(filters);
    char *filters_token = strtok(filters_cpy, "\n");

    while (filters_token != NULL) {
        filtersArr.push_back(std::string(filters_token));
        filters_token = strtok(NULL, "\n");
    }
    std::vector<std::string>filtersFormated = organizeFilters(filtersArr)

        //filtrando linhas
        char *selectedColumnsCpy = strdup(selectedColumns);
    std::vector<std::string> selected_columns;
    char *selected_column = strtok(selectedColumnsCpy, ",");
    while (selected_column != NULL) {
        selected_columns.push_back(std::string(selected_column));
        selected_column = strtok(NULL, ",");
    }

    std::cout << "Processamento:\n";
    for (size_t i = 0; i < lines.size(); ++i) {
        for (size_t j = 0; j < lines[i].size(); ++j) {
            if (i == 0) {
                std::cout << "Linha " << i << ", Coluna " << j << ": " << lines[i][j] << "\n";
            } else {
                for (const auto& selected_column : selected_columns) {
                    if (lines[0][j] == selected_column) {
                        
                    } else {
                        
                    }
                }
            }
        }
    }
    }

int main() {
    const char csv[] = "header1,header2,header3,header4\n1,2,3,4\n5,6,7,8\n9,10,11,12";

    std::cout << "Resultado do processamento do csv:\n";
    processCsv(csv, "header1,header3,header4", "header1>1\nheader3<10\n");    

    return 0;
}

std::vector<std::string> organizeFilters(const std::vector<std::string> filters) {
       const char **filters_vector;
       size_t pos = filters.find("<>!");

        if (pos != std::string::npos) {
            return filters.
        }
}
