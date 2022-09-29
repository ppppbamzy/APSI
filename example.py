#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Created by lizhiwei at 2022/9/29

import pyapsi as apsi

params_string = """{
    "table_params": {
        "hash_func_count": 1,
        "table_size": 1638,
        "max_items_per_bin": 8100
    },
    "item_params": {
        "felts_per_item": 5
    },
    "query_params": {
        "ps_low_degree": 310,
        "query_powers": [ 1, 4, 10, 11, 28, 33, 78, 118, 143, 311, 1555]
    },
    "seal_params": {
        "plain_modulus_bits": 22,

        "poly_modulus_degree": 8192,
        "coeff_modulus_bits": [ 56, 56, 56, 32 ]
    }
}

"""

params = apsi.PSIParams.Load(params_string)
sender_db = apsi.SenderDB(params)

items = apsi.CreateItems()
sender_db.set_data(items)
sender_db.save("./out")