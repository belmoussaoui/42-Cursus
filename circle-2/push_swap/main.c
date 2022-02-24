/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-mous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:03:34 by bel-mous          #+#    #+#             */
/*   Updated: 2022/02/24 10:27:28 by bel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int     insert(t_game *game, int pos)
{
        int             c;
        int             len;
        int             i;
        t_list  *elem;

        c = 0;
        len = 0;
        i = 0;
        elem = game->stack_b;
        while (elem)
        {
                len++;
                elem = elem->next;
        }
        pos = pos % len;
        if (len - pos < pos)
        {
                while (i < len - pos)
                {
                        game->head_index += 1;
                        if (game->head_index >= len)
                        {
                                game->head_index = 0;
                        }
                        printf("rrb\n");
                        c++;
                        reverse_rotate(&game->stack_b);
                        i++;
                }
                c++;
                printf("pa\n");
                push(&game->stack_a, &game->stack_b);
                if (*((int *)game->head->content) > *((int *)game->stack_b->content))
                        game->head_index += 1;
                i = 0;
        }
        else
        {
                while (i < pos)
                {
                        game->head_index -= 1;
                        if (game->head_index < 0)
                        {
                                game->head_index = len - 1;
                        }
                        c++;
                        printf("rb\n");
                        rotate(&game->stack_b);
                        i++;
                }
                c++;
                printf("pa\n");
                push(&game->stack_a, &game->stack_b);
                if (*((int *)game->head->content) > *((int *)game->stack_b->content))
                        game->head_index += 1;
        }
        return (c);
}

int     find_best_stack_a(t_game *game)
{
        int             bscore;
        int             bi;
        int             len;
        t_list  *elem;
        int             i;
        int             s;
        int             j;
        int             pos;
        t_list  *elem2;
        int             c;

        bscore = game->n;
        bi = 0;
        len = 0;
        elem = game->stack_a;
        while (elem)
        {
                len++;
                elem = elem->next;
        }
        i = 0;
        while (i < len)
        {
                s = 0;
                elem = game->stack_a;
                j = 0;
                while (j < i)
                {
                        j++;
                        elem = elem->next;
                }
                if (len - i < i)
                        s = len - i;
                else
                        s = i;
                pos = 0;
                elem2 = game->head;
                while (pos < (game->n
                                - len) && *((int *)elem->content) < *((int *)elem2->content))
                {
                        elem2 = elem2->next;
                        if (elem2 == NULL)
                                elem2 = game->stack_b;
                        pos += 1;
                }
                pos = (game->head_index + pos);
                pos = pos % (game->n - len);
                if ((game->n - len) - pos < pos)
                        pos = (game->n - len) - pos;
                s += pos;
                if (s < bscore)
                {
                        bscore = s;
                        bi = i;
                }
                i++;
        }
        i = 0;
        c = 0;
        if (len - bi < bi)
        {
                while (i < len - bi)
                {
                        c++;
                        printf("rra\n");
                        reverse_rotate(&game->stack_a);
                        i++;
                }
        }
        else
        {
                while (i < bi)
                {
                        c++;
                        printf("ra\n");
                        rotate(&game->stack_a);
                        i++;
                }
        }
        return (c);
}

void    sorting(t_game *game)
{
        int             end;
        int             pos;
        int             c;
        int             i;
        t_list  *elem;

        end = 1;
        pos = 0;
        c = 0;
        i = 0;
        push(&game->stack_a, &game->stack_b);
        game->head = game->stack_b;
        game->head_index = 0;
        c++;
        printf("pb\n");
        while (end < game->n)
        {
                i = 0;
                c += find_best_stack_a(game);
                game->head = game->stack_b;
                while (i < game->head_index)
                {
                        i++;
                        game->head = game->head->next;
                }
                elem = game->head;
                pos = 0;
                while (pos < end && *((int *)game->stack_a->content) < *((int *)elem->content))
                {
                        elem = elem->next;
                        if (elem == NULL)
                                elem = game->stack_b;
                        pos += 1;
                }
                pos = (game->head_index + pos);
                c += insert(game, pos);
                end += 1;
        }
        end = 0;
        while (end < game->n)
        {
                printf("pa\n");
                c++;
                push(&game->stack_b, &game->stack_a);
                end++;
        }
        printf("c = %d\n", c);
}

int     main(void)
{
        t_game game;
        int data[500] = {190, 307, 356, 443, 175, 19, 325, 34, 118, 59, 61, 146,
                435, 68, 201, 365, 405, 270, 178, 123, 212, 416, 486, 8, 393, 29, 72,
                496, 454, 343, 296, 106, 198, 362, 451, 143, 2, 38, 354, 89, 235, 97,
                155, 63, 179, 403, 96, 220, 87, 47, 210, 216, 196, 459, 426, 67, 289,
                132, 94, 497, 488, 116, 455, 338, 65, 331, 140, 368, 320, 412, 278, 359,
                1, 24, 119, 428, 421, 157, 291, 31, 194, 131, 370, 188, 53, 159, 165,
                363, 49, 95, 77, 46, 471, 283, 373, 301, 474, 215, 260, 303, 330, 410,
                112, 134, 290, 319, 139, 120, 73, 487, 167, 76, 332, 401, 15, 383, 371,
                380, 158, 281, 22, 431, 160, 395, 202, 85, 70, 226, 364, 37, 84, 447,
                144, 12, 470, 205, 450, 367, 133, 437, 427, 98, 113, 58, 327, 241, 81,
                444, 225, 242, 282, 246, 266, 164, 394, 111, 124, 456, 110, 346, 79,
                415, 56, 191, 82, 429, 267, 156, 161, 349, 340, 147, 293, 392, 385, 153,
                271, 224, 492, 78, 350, 254, 345, 57, 237, 252, 33, 287, 32, 390, 185,
                204, 400, 336, 462, 318, 141, 458, 317, 409, 176, 292, 122, 316, 323,
                399, 272, 499, 262, 10, 333, 419, 126, 286, 109, 440, 229, 407, 23, 129,
                86, 168, 233, 352, 388, 162, 326, 322, 302, 500, 398, 80, 219, 374, 491,
                208, 16, 478, 214, 45, 105, 66, 6, 195, 75, 377, 489, 50, 7, 99, 13,
                203, 62, 472, 187, 490, 39, 152, 463, 476, 92, 71, 268, 372, 239, 41,
                232, 386, 135, 494, 441, 130, 90, 297, 171, 128, 414, 264, 11, 358, 27,
                54, 127, 206, 342, 259, 249, 314, 172, 305, 163, 145, 263, 257, 170, 44,
                211, 339, 245, 221, 142, 484, 355, 483, 14, 234, 0, 449, 186, 88, 35,
                26, 137, 275, 460, 277, 353, 387, 306, 376, 48, 230, 200, 149, 413, 361,
                51, 366, 193, 445, 300, 43, 21, 473, 479, 269, 337, 402, 250, 448, 207,
                446, 42, 467, 442, 430, 25, 498, 475, 9, 276, 397, 396, 20, 189, 36,
                166, 311, 150, 408, 117, 438, 382, 17, 391, 4, 151, 52, 417, 411, 83,
                60, 341, 480, 308, 312, 389, 227, 351, 357, 238, 434, 240, 115, 453,
                104, 334, 258, 93, 154, 310, 298, 91, 236, 466, 255, 103, 248, 468, 321,
                378, 439, 265, 422, 169, 209, 379, 138, 495, 223, 121, 228, 3, 100, 253,
                482, 148, 423, 69, 420, 256, 274, 360, 28, 173, 218, 74, 452, 477, 182,
                324, 231, 288, 192, 465, 295, 418, 348, 279, 18, 222, 251, 433, 384,
                304, 261, 309, 493, 381, 464, 40, 114, 369, 64, 184, 457, 299, 485, 406,
                313, 329, 461, 328, 273, 102, 424, 284, 244, 469, 108, 217, 432, 344,
                285, 181, 315, 125, 404, 213, 199, 481, 280, 436, 243, 107, 197, 30, 55,
                425, 335, 101, 347, 174, 177, 183, 5, 247, 180, 294, 375};

        game = setup(data);
        print_game(game);
        printf("sorting:\n");
        // insert(&game, 3);
        sorting(&game);
        print_game(game);
        return (0);
}                