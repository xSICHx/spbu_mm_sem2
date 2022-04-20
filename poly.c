#include <stdio.h>
#include <stdlib.h>

struct poly{
    int coef;
    int exp;
    struct poly *next;
};

struct poly *get_monomial(int c, int e) {
    struct poly *temp = (struct poly*)malloc(sizeof(struct poly));
    temp->coef = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

void poly_add_monomial(struct poly *lst, int val, int e){

    struct poly *p = lst;
    struct poly *temp;
    struct poly *ptr;
    do{
        if (p->exp == e){
            p->coef += val;
            // удаляем нули
            if (p->coef == 0 && p->exp != 0){
                temp = lst;

                while (temp->next != p){
                    temp = temp ->next;
                }
                temp->next = p->next;
                free(p);
            }
            return;
        }
        if (p->exp > e){
            temp = get_monomial(p->coef, p->exp);
            p->coef = val;
            p->exp = e;
            ptr = p->next;
            p->next = temp;
            temp->next = ptr;
            return;
        }
        if (p->next) p = p->next;
    } while (p->next);
    // добвочное условие, поскольку иначе последний и предпоследний элемент меняются
    // местами
    if (p->exp > e){
        temp = get_monomial(p->coef, p->exp);
        p->coef = val;
        p->exp = e;
        ptr = p->next;
        p->next = temp;
        temp->next = ptr;
        return;
    }
    temp = get_monomial(val, e);
    p->next = temp;
    //ptr = p->next;
    //temp->next = ptr;
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
    struct poly* p;
    while (lst){
        p = lst;
        lst = lst->next;
        free(p);
    }
}

struct poly* poly_get(const char *s){
    struct poly *lst;
    char *p;
    lst = get_monomial(0,0);
    lst->next = NULL;
    int val = 1, flag = 0, e;
    while (*s != '\0') {
        //случай -x +x
        if ((*s == '-' || *s == '+') && *(s+1) == 'x'){
            if (flag) poly_add_monomial(lst, val, 0);
            flag = 0;
            if (*s == '+') val = 1;
            if (*s == '-') val = -1;
            s++;
        }
        //случай коэфицентов
        if ('0' <= *s && *s <= '9' || *s == '+' || *s == '-') {
            if (flag) poly_add_monomial(lst, val, 0);
            p = NULL;
            flag = 1;
            val = strtol(s, &p, 10);
            s = p;
            if (*s == '\0') poly_add_monomial(lst, val, 0);
        }
        // случай x
        if (*s == 'x'){
            flag = 0;
            if (*(s+1) == '\0'){ poly_add_monomial(lst, val, 1); break;}
            else{
                if (*(s+1) != '^'){ poly_add_monomial(lst, val, 1); s++;}
                else{
                    s += 2;
                    e = strtol(s, &p, 10);
                    s = p;
                    poly_add_monomial(lst, val, e);
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
        poly_add_monomial(lst_new, p->coef, p->exp);
        p = p->next;
    } while (p != NULL);
}

struct poly* poly_add(struct poly* lst1, struct poly* lst2){
    struct poly *result;
    result = poly_get("0");
    poly_copy(result, lst1);
    struct poly *p;
    p = lst2;
    do {
        poly_add_monomial(result, p->coef, p->exp);
        p = p->next;
    } while (p);
    return result;
}

struct poly* poly_mul(struct poly* lst1, struct poly* lst2){
    struct poly *result;
    result = poly_get("0");
    // потому что изначально стоит нулевой элемент
    struct poly *p, *k;
    if (lst1->coef) p = lst1;
    else p = lst1->next;
    if (lst2->coef) k = lst2;
    else k = lst2->next;
    while (p != NULL) {
        while (k != NULL) {
            poly_add_monomial(result, p->coef * k->coef, p->exp + k->exp);
            k = k->next;
        }
        if (lst2->coef) k = lst2;
        else k = lst2->next;
        p = p->next;
    }
    return result;
}

int main() {
    struct poly *lst1, *lst2, *lst3, *lst4;
    lst1 = poly_get("1+2x^2-3x^4-6x^53-100x^71+2x^4-3x^5");
    //10-x+x^2+12x^14-13x^56+300x^332-100-x^2-100x^331+100x^330+112x");
    lst2 = poly_get("x^11-1");//"-523x^63+36+5x^7-15x^2+12x+3x^34+102x^331+x^10-x^10");
    lst3 = poly_add(lst1, lst2);
    poly_print(lst3);
    lst4 = poly_mul(lst1, lst2);
    poly_free(lst3);
    printf("\n");
    poly_print(lst4);
    return 0;
}
