#include "store.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Store* initStore(const char* storeName, const char* fileName)
{
	struct Store* store = malloc(sizeof(struct Store));
	FILE *fp;
	if ((fp = fopen(fileName, "r")))
	{
		int nameLen = strlen(storeName);
		char* nameCopy = malloc(nameLen * sizeof(char));
		strcpy(nameCopy, storeName);
		store->storeName = nameCopy;
		int numberItems = 0;
		fscanf(fp, "%d", &numberItems);
		store->numItems = numberItems;
		store->items = malloc(numberItems * sizeof(struct Item));
		for (int i = 0; i < numberItems; ++i)
		{
			struct Item items;
			char * name = malloc(MAX_LINE_LEN * sizeof(char));
			int price = 0;
			int numInStock = 0;
			fscanf(fp, "%s %d %d", name, &price, &numInStock);
			items.name = name;
			items.price = price;
			items.numInStock = numInStock;
			store->items[i] = items;
		}
		fclose(fp);
	}
	else
	{
		return NULL;
	}
	return store;	
}

struct Item* getCheapestItem(struct Store* store)
{
	int cheapestPrice = store->items[0].price;
	struct Item* cheapest = &store->items[0];
	for (int i = 0; i < store->numItems; ++i)
	{
		if (store->items[i].price < cheapestPrice)
		{
			cheapestPrice = store->items[i].price;
			cheapest = &store->items[i];
		}
		
	}
	return cheapest;
}

void deallocateStore(struct Store* store)
{
	for (int i = 0; i < store->numItems; ++i)
	{
		free(store->items[i].name);
	}
	free(store->items);
	free(store->storeName);
        free(store);
	
	
}

void printStoreItems(const struct Store* store)
{
	printf("%s has the following items:\n", store->storeName);
	for (int i = 0; i < store->numItems; ++i)
	{
		printf("Item #%d: %s, Price: %d, Number in stock: %d\n", i + 1, store->items[i].name, store->items[i].price, store->items[i].numInStock);
	}
}
