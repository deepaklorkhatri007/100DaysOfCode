from flask import Flask, render_template, request, redirect

def search4letter(phrase:str, letters:str = 'aeiou') ->set :
    return set(letters).intersection(set(phrase))

app = Flask(__name__)

@app.route('/')
def hello() -> '302':
    return redirect('/entry')

@app.route('/search4', methods=['POST'])
def do_search()->str:
    phrase = request.form['phrase']
    letters = request.form['letters']
    title = 'Here are your results : '
    results = str(str(search4letter(phrase, letters)))
    return render_template('results.html',
                            the_phrase = phrase,
                            the_letters = letters,
                            the_title = title,
                            the_results = results)


@app.route('/entry')
def entry_page() -> 'html':
    return render_template('entry.html', the_title = 'Welcome to search4letters on the web')

if __name__ == '__main__':
    app.run(debug=True)
