/**
 * @file pbl-type-list.c
 * @brief Implementation of the base type list that keeps track of the locally available types.
 * @author Luna Klatzer
 * @date 2022-04-16
 * @copyright Copyright (c) 2021 - 2022
 */

#include "libpbl/core/pbl-type-list.h"

// ---- Initialisation of the global type list ------------------------------------------------------------------------

PblType_T *PblCreateNewType(size_t size, void *type_template, const char *name, bool user_defined, bool definable,
                            bool primitive) {
  PblType_T *type = (PblType_T *) PblMalloc(sizeof(PblType_T));
  *type = (PblType_T){.actual_size = size,
                      .type_template = type_template,
                      .name = name,
                      .is_builtin = user_defined,
                      .definable = definable,
                      .primitive = primitive};
  return type;
}

void PblInitTypeList(PblTypeList_T *list) {
  // Default size on init is 50
  list->t_items = (PblType_T **) PblMalloc(sizeof(PblType_T) * 50);
  list->alloc_len = 50;
}

void PblAddTypeToTypeList(PblTypeList_T *list, PblType_T *type) {
  // If there is not enough space to add a new item, extend the list
  if (list->alloc_len == list->t_amount) {
    list->t_items = (PblType_T **) PblRealloc(list->t_items, sizeof(PblType_T *) * (list->alloc_len * 50));
    list->alloc_len += 50;
  }
  list->t_items[list->t_amount] = type;
  list->t_amount++;
}

// ---- End of Initialisation of the global type list -----------------------------------------------------------------
