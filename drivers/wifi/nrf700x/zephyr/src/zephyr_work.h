/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @brief Header containing work specific declarations for the
 * Zephyr OS layer of the Wi-Fi driver.
 */

#ifndef __WORK_H__
#define __WORK_H__

extern struct k_work_q zep_wifi_bh_q;
struct zep_work_item {
	bool in_use;
	struct k_work work;
	unsigned long data;
	void (*callback)(unsigned long data);
};

struct zep_work_item *work_alloc(void);

void work_init(struct zep_work_item *work, void (*callback)(unsigned long callbk_data),
		  unsigned long data);

void work_schedule(struct zep_work_item *work);

void work_kill(struct zep_work_item *work);

void work_free(struct zep_work_item *work);

#endif /* __WORK_H__ */
