import mysql.connector

dbconfig = {'host': '127.0.0.1',
            'user': 'dragon',
            'password': 'master',
            'database':'python'}

conn = mysql.connector.connect(**dbconfig)
cursor = conn.cursor()

_SQL = """ insert into tasks
            (task, time)
            values
            (%s, %s)"""

cursor.execute(_SQL, ('complete 100DaysOfCode work', 'now'))
conn.commit()
cursor.close()
conn.close()