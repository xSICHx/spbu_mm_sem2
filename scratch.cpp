#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct poly{
    int coef;
    int exp;
    struct poly *next;
};

char *slice(const char *s, int beg, int end){
    char *result = malloc(end-beg+1);
    for (int i = beg; i <= end; i++){
        result[i-beg] = s[i];
    }

    return result;
}

void poly_add(struct poly *lst, int val, int e){
    struct poly *p = lst;
    struct poly *temp;
    struct poly *ptr;
    do{
        if (p->exp == e){ p->coef += val; return;}
        if (p->exp > e){
            temp = (struct poly*)malloc(sizeof(struct poly));
            temp->coef = p->coef;
            temp->exp = p->exp;
            p->coef = val;
            p->exp = e;
            ptr = p->next;
            p->next = temp;
            temp->next = ptr;
            return;
        }
        if (p->next != NULL) p = p->next;
    } while (p->next != NULL);
    // добвочное условие, поскольку иначе последний и предпоследний элемент меняются
    // местами
    if (p->exp > e){
        temp = (struct poly*)malloc(sizeof(struct poly));
        temp->coef = p->coef;
        temp->exp = p->exp;
        p->coef = val;
        p->exp = e;
        ptr = p->next;
        p->next = temp;
        temp->next = ptr;
        return;
    }
    temp = (struct poly*)malloc(sizeof(struct poly));
    temp->coef = val;
    temp->exp = e;
    ptr = p->next;
    p->next = temp;
    temp->next = ptr;
}

void poly_print(struct poly *lst)
{
    struct poly *p;
    p = lst;
    do {
        if (p->coef > 0){
            if (p->exp == 0) printf("%d", p->coef);
            else {
                if (p->coef == 1) printf("+x^%d", p->exp);
                else printf("+%dx^%d", p->coef, p->exp);}
        }
        else{
            if (p->exp == 0) printf("%d", p->coef);
            else {
                if (p->coef == -1) printf("-x^%d", p->exp);
                else printf("%dx^%d", p->coef, p->exp);}
        }
        p = p->next;
    } while (p != NULL);
}


void poly_free(struct poly* lst){
    free(lst->next);
    free(lst);
}

struct poly* poly_get(const char *s){
    struct poly *lst;
    lst = (struct poly*)malloc(sizeof(struct poly));
    lst->coef = 0;
    lst->exp = 0;
    lst->next = NULL;
    int i = 0; unsigned long long len = strlen(s);
    int val = 1, p, flag = 0, e;
    char *val_str; char *e_str;
    while (i < len){
        //случай -x +x
        if (i<len-1 && (s[i] == '-' || s[i] == '+') && s[i+1] == 'x'){
            flag = 0;
            if (s[i] == '+') val = 1;
            if (s[i] == '-') val = -1;
            ++i;
        }
        //случай коэфицентов
        if ('0' <= s[i] && s[i] <= '9' || s[i] == '+' || s[i] == '-') {
            p = i;
            if (i == 0 && ('0' <= s[i] && s[i] <= '9')) flag = 1; // начало - х^0
            while (i < len && '0' <= s[i] && s[i] <= '9'|| s[i] == '+' || s[i] == '-') {
                if (s[i] == '+' || s[i] == '-'){
                    if (flag == 0) flag = 1;
                    else {
                        flag = 0;
                        val_str = slice(s, p, i - 1);
                        val = strtol(val_str, NULL, 10);
                        free(val_str);
                        poly_add(lst, val, 0);
                        //printf("%d ", val);
                        break;
                    }
                }
                ++i;
            }
            val_str = slice(s, p, i);
            val = strtol(val_str, NULL, 10);
            free(val_str);
            if (i == len) poly_add(lst, val, 0); /*printf("%d ", val);*/
        }
        // случай x
        if (s[i] == 'x'){
            flag = 0;
            if (i == len - 1){ poly_add(lst, val, 1); /*printf("%dx ", val);*/ break;}
            else{
                if (s[i+1] != '^'){ poly_add(lst, val, 1); /*printf("%dx ", val);*/ ++i;}
                else{
                    i += 2;
                    p = i;
                    while (i < len && '0' <= s[i] && s[i] <= '9'){
                        ++i;
                    }
                    e_str = slice(s, p, i);
                    e = strtol(e_str, NULL, 10);
                    free(e_str);
                    poly_add(lst, val, e);
                    //printf("%dx^%d ", val, e);
                }
            }
        }
    }
    return lst;
}

void poly_copy(struct poly *lst_new, struct poly *lst){
    struct poly *p;
    p = lst;
    do {
        poly_add(lst_new, p->coef, p->exp);
        p = p->next;
    } while (p != NULL);
}

struct poly* poly_plus(struct poly* lst1, struct poly* lst2){
    struct poly *result;
    result = poly_get("0");
    poly_copy(result, lst1);
    struct poly *p;
    p = lst2;
    do {
        poly_add(result, p->coef, p->exp);
        p = p->next;
    } while (p != NULL);
    return result;
}


int main() {
    struct poly *lst1;
    struct poly *lst2;
    struct poly *lst3;
    lst1 = poly_get("10-x+x^2+12x^14-13x^56+300x^332+10-100-x^2-100x^331+100x^330+112x");
    lst2 = poly_get("-523x^63+36+5x^7-15x^2+10+1+1+1+1-12x+3x^34+102x^331+x^10-x^10");
    lst3 = poly_plus(lst1, lst2);
    poly_print(lst3);
    return 0;
}
