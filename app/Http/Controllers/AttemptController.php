<?php

namespace App\Http\Controllers;

use App\Http\Requests\CreateAttemptRequest;
use App\Http\Requests\UpdateAttemptRequest;
use App\Repositories\AttemptRepository;
use App\Http\Controllers\AppBaseController;
use Illuminate\Http\Request;
use Flash;
use Response;

class AttemptController extends AppBaseController
{
    /** @var AttemptRepository $attemptRepository*/
    private $attemptRepository;

    public function __construct(AttemptRepository $attemptRepo)
    {
        $this->attemptRepository = $attemptRepo;
    }

    /**
     * Display a listing of the Attempt.
     *
     * @param Request $request
     *
     * @return Response
     */
    public function index(Request $request)
    {
        $attempts = $this->attemptRepository->all();

        return view('attempts.index')
            ->with('attempts', $attempts);
    }

    /**
     * Show the form for creating a new Attempt.
     *
     * @return Response
     */
    public function create()
    {
        return view('attempts.create');
    }

    /**
     * Store a newly created Attempt in storage.
     *
     * @param CreateAttemptRequest $request
     *
     * @return Response
     */
    public function store(CreateAttemptRequest $request)
    {
        $input = $request->all();

        $attempt = $this->attemptRepository->create($input);

        Flash::success('Attempt saved successfully.');

        return redirect(route('attempts.index'));
    }

    /**
     * Display the specified Attempt.
     *
     * @param int $id
     *
     * @return Response
     */
    public function show($id)
    {
        $attempt = $this->attemptRepository->find($id);

        if (empty($attempt)) {
            Flash::error('Attempt not found');

            return redirect(route('attempts.index'));
        }

        return view('attempts.show')->with('attempt', $attempt);
    }

    /**
     * Show the form for editing the specified Attempt.
     *
     * @param int $id
     *
     * @return Response
     */
    public function edit($id)
    {
        $attempt = $this->attemptRepository->find($id);

        if (empty($attempt)) {
            Flash::error('Attempt not found');

            return redirect(route('attempts.index'));
        }

        return view('attempts.edit')->with('attempt', $attempt);
    }

    /**
     * Update the specified Attempt in storage.
     *
     * @param int $id
     * @param UpdateAttemptRequest $request
     *
     * @return Response
     */
    public function update($id, UpdateAttemptRequest $request)
    {
        $attempt = $this->attemptRepository->find($id);

        if (empty($attempt)) {
            Flash::error('Attempt not found');

            return redirect(route('attempts.index'));
        }

        $attempt = $this->attemptRepository->update($request->all(), $id);

        Flash::success('Attempt updated successfully.');

        return redirect(route('attempts.index'));
    }

    /**
     * Remove the specified Attempt from storage.
     *
     * @param int $id
     *
     * @throws \Exception
     *
     * @return Response
     */
    public function destroy($id)
    {
        $attempt = $this->attemptRepository->find($id);

        if (empty($attempt)) {
            Flash::error('Attempt not found');

            return redirect(route('attempts.index'));
        }

        $this->attemptRepository->delete($id);

        Flash::success('Attempt deleted successfully.');

        return redirect(route('attempts.index'));
    }
}
