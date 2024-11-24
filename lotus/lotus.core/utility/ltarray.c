#include "ltarray.h"

/* LT VALUE */

void ltDestroyValue(LTvalue* v) {
    v->type = LOTUS_NONE;
    free(v->value);
    free(v);
}

LTvalue* ltMakeValue(LTvalueType type, void* value) {
    LTvalue* v = (LTvalue*)malloc(sizeof(LTvalue));
    if (!v) {
        // _ecLogError("failed to allocate dynamic value");
        return NULL;
    }
    v->type = type;
    v->value = value;
    return v;
}

LTvalue* ltMakeInt(int value) {
    LTvalue* v = (LTvalue*)malloc(sizeof(LTvalue));
    if (!v) {
        // _ecLogError("failed to allocate dynamic value");
        return NULL;
    }

    v->type = LOTUS_INT;
    
    v->value = (int*)malloc(sizeof(int));
    if (!v->value) {
        // _ecLogError("failed to allocate integer");
        v->value = NULL;
        return v;
    }; *(int*)v->value = value;
    
    return v;
}

LTvalue* ltMakeFloat(float value) {
    LTvalue* v = (LTvalue*)malloc(sizeof(LTvalue));
    if (!v) {
        // _ecLogError("failed to allocate dynamic value");
        return NULL;
    }

    v->type = LOTUS_FLOAT;
    
    v->value = (float*)malloc(sizeof(float));
    if (!v->value) {
        // _ecLogError("failed to allocate float");
        v->value = NULL;
        return v;
    }; *(float*)v->value = value;
    
    return v;
}

LTvalue* ltMakeString(const char* value) {
    LTvalue* v = (LTvalue*)malloc(sizeof(LTvalue));
    if (!v) {
        // _ecLogError("failed to allocate dynamic value");
        return NULL;
    }

    v->type = LOTUS_STRING;
    v->value = strdup(value);
    return v;
}

int ltGetInt(LTvalue* v) {
    return *(int*)v->value;
}

char* ltGetString(LTvalue* v) {
    return (char*)v->value;
}

float ltGetFloat(LTvalue* v) {
    return *(float*)v->value;
}

/* LT ARRAY */
LTarray* ltMakeArray(int max, int resize) {
    LTarray* arr = (LTarray*)malloc(sizeof(LTarray));
    if (!arr) {
        // _ecLogError("failed to allocate dynamic array");
        return NULL;
    }

    arr->count = 0;
    arr->max = max;
    arr->resize = resize;

    arr->arr = (LTvalue**)malloc(max*sizeof(void*));
    if (!arr->arr) {
        free(arr);
        // _ecLogError("failed to allocate dynamic array");
        return NULL;
    }; return arr;
}

void ltDestroyArray(LTarray* inArr) {
    // free associeced data
    for(int i = 0; i < inArr->count; i++) {
        ltDestroyValue(inArr->arr[i]);
    }; free(inArr->arr);
    inArr->resize = 0;
    inArr->count = 0;
    inArr->max = 0;
    free(inArr);
}

LTerrorType ltResizeArray(LTarray* inArr) {
    LTerrorType err = LOTUS_ERR_NONE;
    
    LTvalue** temp = (LTvalue**)realloc(inArr->arr, inArr->max+inArr->resize * sizeof(LTvalue*));
    if (!temp) {
        err = LOTUS_ERR_MALLOC;
        return err;
    }
    
    inArr->max += inArr->resize;
    inArr->arr = temp;
    return err;
}

LTerrorType ltInsertArray(LTarray* inArr, int index, LTvalue* value) {
    LTerrorType err = LOTUS_ERR_NONE;
    if (!inArr || index < 0) { return err; }

    if (index >= inArr->max || inArr->count == inArr->max) {
        err = ltResizeArray(inArr);
    }

    if (!err) {
        inArr->arr[index] = value;
        inArr->count++;
    }; return err;
}

LTerrorType ltInsertArrayV(LTarray* inArr, int count, LTvalue** values) {
    LTerrorType err = LOTUS_ERR_NONE;
    if (inArr->count + count >= inArr->max || inArr->count == inArr->max) {
        err = ltResizeArray(inArr);
    }
    if (!err) {
        for (int i = 0; i < count; i++) {
            inArr->arr[inArr->count] = values[i];
            inArr->count++;
        }
    }; return err;
}

LTvalue* ltPopArray(LTarray* inArr, int index) {
    LTerrorType err = LOTUS_ERR_NONE;
    
    if (!inArr || index >= inArr->max) {
        return NULL;
    }

    void* value = inArr->arr[index];

    for (int i = index; i < inArr->count-1; i++) {
        inArr->arr[i] = inArr->arr[i + 1];
    };inArr->arr[inArr->count-1] = NULL;
    
    inArr->count--;
    return value;
}

LTvalue* ltQueryArray(LTarray* inArr, int index) {
    LTerrorType err = LOTUS_ERR_NONE;
    
    if (!inArr || index >= inArr->max) {
        return NULL;
    }
    
    return inArr->arr[index];
}

int ltQueryArrayInt(LTarray* inArr, int index) {
    return ltGetInt(ltQueryArray(inArr, index));
}

float ltQueryArrayFloat(LTarray* inArr, int index) {
    return ltGetFloat(ltQueryArray(inArr, index));
}

char* ltQueryArrayString(LTarray* inArr, int index) {
    return ltGetString(ltQueryArray(inArr, index));
}
