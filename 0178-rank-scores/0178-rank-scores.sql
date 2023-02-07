# Write your MySQL query statement below
# orderby

# declare rank int;
# set rank=1;
select s1.score,(
        select count(distinct s2.score)
        from scores s2
        where 
            s2.score>=s1.score
        )as 'rank'
        from scores s1 order by score desc;