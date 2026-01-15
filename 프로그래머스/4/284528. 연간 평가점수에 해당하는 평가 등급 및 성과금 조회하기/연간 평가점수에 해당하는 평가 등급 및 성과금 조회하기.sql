WITH AvgScores AS (
    SELECT
        e.EMP_NO,
        e.EMP_NAME,
        e.SAL,
        AVG(g.SCORE) AS AVG_SCORE
    FROM HR_EMPLOYEES e
    JOIN HR_GRADE g ON e.EMP_NO = g.EMP_NO
    GROUP BY e.EMP_NO, e.EMP_NAME, e.SAL
)
SELECT
    EMP_NO,
    EMP_NAME,
    CASE
        WHEN AVG_SCORE >= 96 THEN 'S'
        WHEN AVG_SCORE >= 90 THEN 'A'
        WHEN AVG_SCORE >= 80 THEN 'B'
        ELSE 'C'
    END AS GRADE,
    CASE
        WHEN AVG_SCORE >= 96 THEN SAL * 0.2
        WHEN AVG_SCORE >= 90 THEN SAL * 0.15
        WHEN AVG_SCORE >= 80 THEN SAL * 0.1
        ELSE 0
    END AS BONUS
FROM AvgScores
ORDER BY EMP_NO ASC;