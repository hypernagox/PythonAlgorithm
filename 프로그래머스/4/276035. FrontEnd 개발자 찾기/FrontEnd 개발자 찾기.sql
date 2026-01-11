SELECT
DISTINCT
    d.ID,
    d.EMAIL,
    d.FIRST_NAME,
    d.LAST_NAME
FROM 
    (
        SELECT CODE
        FROM SKILLCODES
        WHERE CATEGORY = 'Front End'
    ) c
JOIN DEVELOPERS d ON (c.CODE & d.SKILL_CODE) != 0
ORDER BY d.ID ASC;
    